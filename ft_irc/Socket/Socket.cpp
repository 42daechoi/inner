#include "Socket.hpp"

Socket::Socket() : _servfd(-1) {}

Socket::Socket(int domain, int type, int protocol) {
	_servfd = socket(domain, type, protocol);
	if (_servfd < 0)
		perr("Error: socket error");
}

Socket::~Socket() {
	close(_servfd);
}

void Socket::bind(int port) {
	struct sockaddr_in serv_addr;

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);
	if (::bind(_servfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		perr("Error: bind error");
}

void Socket::listen() {
	if (::listen(_servfd, 5) == -1)
		perr("Error: listen error");
}

int Socket::accept() {
	int					clntfd;
	struct sockaddr_in	clnt_addr;
	socklen_t			ca_size = sizeof(clnt_addr);

	if ((clntfd = ::accept(_servfd, (struct sockaddr*)&clnt_addr, &ca_size)) == -1)
		perr("Error: accept error");
	return clntfd;
}

string Socket::recv(int clntfd) {
	char	buffer[4096];
	int 	rsize = ::recv(clntfd, buffer, sizeof(buffer), 0);

	if (errno == EWOULDBLOCK)
		return "";
	if (rsize == -1)
		perr("Error: recv error");
	return string(buffer, rsize);
}

void Socket::send(const string &msg, int clntfd) {
	if (::send(clntfd, msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
}

int Socket::getSock() {
	return _servfd;
}