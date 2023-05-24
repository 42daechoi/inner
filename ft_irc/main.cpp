#include "header.hpp"
#include "Socket/Socket.hpp"
#include "Command/Command.hpp"

int main(int ac, char **av)
{
	if (ac != 3) 
		perr("Usage: ./ircserv <port> <password>");
	string password = av[2];
	ofstream logFile("log.txt");
	if (!logFile.is_open())
		perr("log.txt open fail\n");
	Socket ss = Socket(PF_INET, SOCK_STREAM, 0);
	ss.bind(check_port(av));
	fcntl(ss.getSock(), F_SETFL, O_NONBLOCK);
	ss.listen();

	vector<struct pollfd> vfds;
	vfds.push_back(makePollfd(ss.getSock()));

	vector<Client *>		clntList;
	vector<Channel *>		chList;

	while (1) {

		if (poll(&vfds[0], vfds.size(), 0) == -1)
			perr("Error: poll error");

		if (vfds[0].revents & POLLIN) {
			string 	msg;
			int		clntfd = ss.accept();
			Client 	*clnt = new Client(clntfd);

			fcntl(clntfd, F_SETFL, O_NONBLOCK);
			printOutput(logFile, "client connected\n");
			vfds.push_back(makePollfd(clntfd));
			clntList.push_back(clnt);
			if (clntList.size() + 1 > MAX_SOCKET)
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
						printOutput(logFile, "client end\n");
						quitClient(clntfd, vfds, clntList, i, chList);
						break;
					}
					else {
						Command cmd = Command(msg, clntList[i - 1], clntList, chList, password, logFile);
						printInput(logFile, msg);
						if (cmd.execute() == -1)
							incorrectPassword(clntfd, vfds, clntList, i);
						noMemberChannel(chList);
						break;
					}
				}
			}
		}
	}
	return 0;
}