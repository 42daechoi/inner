#ifndef SOCKET_HPP
# define SOCKET_HPP

# include "header.hpp"

class Socket {
	public:
		Socket();
		Socket(int domain, int type, int protocol);
		~Socket();

		void	bind(int port);
		void	listen();
		void	accept();
		string	recv();
		void	send(const string &msg);

		int getServSock();
		int getClntSock();
	private:
		int _servfd;
		int _clntfd;
};

#endif