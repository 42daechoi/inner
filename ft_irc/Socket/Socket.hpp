#ifndef SOCKET_HPP
# define SOCKET_HPP

# include "../header.hpp"

class Socket {
	public:
		Socket();
		Socket(int domain, int type, int protocol);
		~Socket();

		void	bind(int port);
		void	listen();
		int		accept();
		string	recv(int clntfd);
		void	send(const string &msg, int clntfd);

		int getSock();
	private:
		int _servfd;
};

#endif