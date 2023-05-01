#include "header.hpp"
#include "Socket.hpp"
#include "Command.hpp"

void print_map(map<string, Client> m) {
	map<string, Client>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
		cout << "{" << (*it).first << "}\n";
}

int main(int ac, char **av)
{
	if (ac != 3) 
		perr("Usage: ./ircserv <port> <password>");

	Socket ss = Socket(PF_INET, SOCK_STREAM, 0);
	ss.bind(check_port(av));
	ss.listen();

	vector<struct pollfd> vfds;
	struct pollfd servpoll;
	servpoll.fd = ss.getSock();
	servpoll.events = POLLIN;
	vfds.push_back(servpoll);

	map<string, Client> clntList;
	
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
			string msg = ss.recv(clntfd);
			Client clnt = Client(clntfd);
			Command cmd = Command(msg, clnt);
			cmd.execute();
			unsigned long before = clntList.size();
			clntList.insert(make_pair(clnt.getNickname(), clnt));
			if (before == clntList.size()) {
				ss.send("same nickname exist.\n", clntfd);
				vfds.pop_back();
				close(clntfd);
			}
			else
				ss.send("create client list.\n", clntfd);
			print_map(clntList);
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
				// Command cmd(msg, clnt);
				// cmd.printCommand();
				ss.send(msg, clntfd);
			}
		}
	}
	return 0;
}

// int main(int ac, char **av)
// {
// 	if (ac != 3) 
// 		perr("Usage: ./ircserv <port> <password>");

// 	Socket ss = Socket(PF_INET, SOCK_STREAM, 0);
// 	ss.bind(check_port(av));
// 	fcntl(ss.getSock(), F_SETFL, O_NONBLOCK);
// 	ss.listen();

// 	vector<struct pollfd> vfds;
// 	struct pollfd servpoll;
// 	servpoll.fd = ss.getSock();
// 	servpoll.events = POLLIN;
// 	vfds.push_back(servpoll);

// 	map<string, Client> clntList;
	
// 	while (1) {

// 		if (poll(&vfds[0], vfds.size(), -1) == -1)
// 			perr("Error: poll error");

// 		if (vfds[0].revents & POLLIN) {
// 			string 	msg;
// 			int		clntfd = ss.accept();
// 			Client 	clnt = Client(clntfd);

// 			fcntl(clntfd, F_SETFL, O_NONBLOCK);
// 			cout << clntfd << "/client connected\n";
// 			struct pollfd clntpoll;
// 			clntpoll.fd = clntfd;
// 			clntpoll.events = POLLIN;
// 			vfds.push_back(clntpoll);
// 			while (1) {
// 				msg = ss.recv(clntfd);
// 				else if (errno == EAGAIN || errno == EWOULDBLOCK)
// 					continue;
// 				else {
// 					Command cmd = Command(msg, clnt);
// 					cmd.execute();
// 				}
// 			}


// 			unsigned long before = clntList.size();
// 			clntList.insert(make_pair(clnt.getNickname(), clnt));
// 			if (before == clntList.size()) {
// 				ss.send("same nickname exist.\n", clntfd);
// 				vfds.pop_back();
// 				close(clntfd);
// 			}
// 			else
// 				ss.send("create client list.\n", clntfd);
// 			print_map(clntList);
// 		}

// 		for (size_t i = 1; i < vfds.size(); i++) {
// 			if (vfds[i].revents & POLLIN) {
// 				int clntfd = vfds[i].fd;
// 				string msg = ss.recv(clntfd);
// 				if (msg.empty()) {
// 					cout << "client end\n";
// 					close(clntfd);
// 					vfds.erase(vfds.begin() + i);
// 					continue ;
// 				}
// 				// Command cmd(msg, clnt);
// 				// cmd.printCommand();
// 				ss.send(msg, clntfd);
// 			}
// 		}
// 	}
// 	return 0;
// }