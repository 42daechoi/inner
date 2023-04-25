#include "header.hpp"
#include "Socket.hpp"

int main(int ac, char **av)
{
	if (ac != 3) 
		perr("Usage: ./ircserv <port> <password>");
	
	Socket ss = Socket(PF_INET, SOCK_STREAM, 0);
	ss.bind(check_port(av));
	ss.listen();

	struct pollfd fds[1];
	fds[0].fd = ss.getClntSock();
	fds[0].events = POLLIN;

	while (1) {
		if (poll(fds, 1, -1) == -1)
			perr("Error: poll error");
		if (fds[0].revents & POLLIN) {
			ss.accept();
			cout << "client connected\n";
			fds[0].fd = ss.getClntSock();
			fds[0].events = POLLIN;
		}
		if (fds[0].revents & POLLIN) {
			string msg = ss.recv();
			cout << msg << "\n";
			ss.send(msg);
		}
	}
	return 0;
}