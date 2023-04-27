#include "header.hpp"
#include "Socket.hpp"
#include "Parser.hpp"

// int main(int ac, char **av)
// {
// 	if (ac != 3) 
// 		perr("Usage: ./ircserv <port> <password>");
	
// 	Socket ss = Socket(PF_INET, SOCK_STREAM, 0);
// 	ss.bind(check_port(av));
// 	ss.listen();

// 	struct pollfd fds[CLIENT_MAX];
// 	fds[0].fd = ss.getServSock();
// 	fds[0].events = POLLIN;
// 	for (int i = 1; i < CLIENT_MAX; i++) {
// 		fds[i].fd = -1;
// 		fds[i].events = POLLIN;
// 	}
// 	while (1) {
// 		if (poll(fds, 1, -1) == -1)
// 			perr("Error: poll error");
// 		if (fds[0].revents & POLLIN) {
// 			ss.accept();
// 			cout << fds[0].fd << " : client connected\n";
// 			fds[0].fd = ss.getClntSock();
// 			fds[0].events = POLLIN;
// 			while (1) {
// 				string msg = ss.recv();
// 				if (msg.empty()) {
// 					cout << "end client\n";
// 					break ;
// 				}
// 				cout << "수신 완료 : " << msg << endl;
// 				ss.send(msg);
// 			}
// 		}
// 	}
// 	return 0;
// }

int main(int ac, char **av)
{
	if (ac != 3) 
		perr("Usage: ./ircserv <port> <password>");

	Socket ss = Socket(PF_INET, SOCK_STREAM, 0);
	ss.bind(check_port(av));
	ss.listen();

	vector<struct pollfd> vfds;
	struct pollfd servpoll;
	servpoll.fd = ss.getServSock();
	servpoll.events = POLLIN;
	vfds.push_back(servpoll);
	
	while (1) {

		if (poll(&vfds[0], vfds.size(), -1) == -1)
			perr("Error: poll error");

		if (vfds[0].revents & POLLIN) {
			int clntfd = ss.accept();
			cout << clntfd << "/client connected\n";
			struct pollfd clntpoll;
			clntpoll.fd = clntfd;
			clntpoll.events = POLLIN;
			vfds.push_back(clntpoll);
		}

		for (size_t i = 1; i < vfds.size(); i++) {
			if (vfds[i].revents & POLLIN) {
				int clntfd = vfds[i].fd;
				string msg = ss.recv(clntfd);
				if (msg.empty()) {
					cout << "client end\n";
					close(clntfd);
					vfds.erase(vfds.begin() + i);
					continue ;
				}
				Parser ps(msg);
				ps.printCommand();
				ss.send(msg, clntfd);
			}
		}
	}
	return 0;
}