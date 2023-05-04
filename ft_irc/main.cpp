#include "header.hpp"
#include "Socket.hpp"
#include "Command.hpp"

void print_List(vector<Client> v) {
	vector<Client>::iterator it;
	cout << "{";
	for (it = v.begin(); it != v.end(); it++)
		cout << (*it).getNickname() << ",";
	cout << "}\n";
}

int main(int ac, char **av)
{
	if (ac != 3) 
		perr("Usage: ./ircserv <port> <password>");

	Socket ss = Socket(PF_INET, SOCK_STREAM, 0);
	ss.bind(check_port(av));
	fcntl(ss.getSock(), F_SETFL, O_NONBLOCK);
	ss.listen();

	vector<struct pollfd> vfds;
	struct pollfd servpoll;
	servpoll.fd = ss.getSock();
	servpoll.events = POLLIN;
	vfds.push_back(servpoll);

	vector<Client>		clntList;

	vector<Channel>		chList;

	while (1) {

		if (poll(&vfds[0], vfds.size(), 0) == -1)
			perr("Error: poll error");

		if (vfds[0].revents & POLLIN) {
			string 	msg;
			int		clntfd = ss.accept();
			Client 	clnt = Client(clntfd);

			fcntl(clntfd, F_SETFL, O_NONBLOCK);
			cout << clntfd << "/client connected\n";
			struct pollfd clntpoll;
			clntpoll.fd = clntfd;
			clntpoll.events = POLLIN;
			vfds.push_back(clntpoll);
			clntList.push_back(clnt);
			// if (clntList.size() + 1 > OPEN_MAX) 왠진 모르겠지만 OPEN_MAX 우분투에서 안먹음..ㅜ
			if (clntList.size() + 1 > 32)
				perr("Error: out of range descriptor");
			continue;
		}

		for (size_t i = 1; i < vfds.size(); i++) {
			if (vfds[i].revents & POLLIN) {
				int clntfd = vfds[i].fd;
				while (1) {
					string msg = ss.recv(clntfd);
					if (errno == EWOULDBLOCK)
						continue;
					else if (msg.empty() || msg.substr(0, 4) == "QUIT") {
						cout << "client end\n";
						close(clntfd);
						vfds.erase(vfds.begin() + i);
						clntList.erase(clntList.begin() + i - 1);
						break;
					}
					else {
						Command cmd = Command(msg, clntList[i - 1], clntList, chList);
						cout << "I " << msg;
						cmd.execute();
						// ss.send(msg, clntfd);
						// print_List(clntList);
						break;
					}
				}
			}
		}
	}
	return 0;
}