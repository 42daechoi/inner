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
		int	ret = poll(&vfds[0], vfds.size(), 0);
		
		if (ret == -1)
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
		}

		for (size_t i = 1; i < vfds.size(); i++) {
			if (vfds[i].revents & POLLIN) {
				int clntfd = vfds[i].fd;
				
				string msg = ss.recv(clntfd);
				
				if (msg.empty() || msg.substr(0, 4) == "QUIT") {
					printOutput(logFile, "client end\n");
					quitClient(clntfd, vfds, clntList, i, chList);
					break;
				}
				else {
					clntList[i - 1]->addMsg(msg);
					if (*(--msg.end()) == '\n')
					{
						if (clntList[i - 1]->getMsg()[0] >= 'A' && clntList[i - 1]->getMsg()[0] <= 'Z')
						{
							Command cmd = Command(clntList[i - 1]->getMsg(), clntList[i - 1], clntList, chList, password, logFile);
							printInput(logFile, clntList[i - 1]->getMsg());
							if (cmd.execute() == -1)
								incorrectPassword(clntfd, vfds, clntList, i);
							noMemberChannel(chList);
							clntList[i - 1]->setMsg("");
							break;
						}
						else
							incorrectPassword(clntfd, vfds, clntList, i);
					}
				}
			}
		}
	}
	for (int i = 0; i < (int)chList.size(); i++)
		delete chList[i];
	for (int i = 0; i < (int)clntList.size(); i++)
		delete clntList[i];
	return 0;
}