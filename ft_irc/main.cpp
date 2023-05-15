#include "header.hpp"
#include "Socket.hpp"
#include "Command.hpp"

void noMemberChannel(vector<Channel> &chList) {
	vector<Channel>::iterator it;
	for (it = chList.begin(); it != chList.end() ; it++) {
		if (it->getMemberList().size() == 0)
			chList.erase(it);
	}
}

int main(int ac, char **av)
{
	if (ac != 3) 
		perr("Usage: ./ircserv <port> <password>");
	std::ofstream logFile("log.txt");
	if (!logFile.is_open())
		perr("log.txt open fail\n");
	Socket ss = Socket(PF_INET, SOCK_STREAM, 0);
	
	ss.bind(check_port(av));
	// fcntl(ss.getSock(), F_SETFL, O_NONBLOCK);
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

			// fcntl(clntfd, F_SETFL, O_NONBLOCK);
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
						//quit할때 속해있던 채널에서도 나가줘야함 그리고 채널이 0명이여서 채널 자체가 사라져야될때 leaks남
						logFile << "client end\n";
						close(clntfd);
						vfds.erase(vfds.begin() + i);
						clntList[i - 1].delChannel();
						noMemberChannel(chList);
						clntList.erase(clntList.begin() + i - 1);
						break;
					}
					else {
						Command cmd = Command(msg, clntList[i - 1], clntList, chList);
						logFile << "I " << msg << endl;
						string buffer = cmd.execute();
						if (buffer != "")
							logFile << "O " << buffer << endl;
						ss.send(msg, clntfd);
						for (int j = 0; j < (int)clntList[i - 1].getJoinList().size(); j++)
							cout << "new/" << clntList[i - 1].getJoinList()[0]->getMemberList()[j]->getClntfd() << endl;
						noMemberChannel(chList);
						break;
					}
				}
			}
		}
	}
	return 0;
}