#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "header.hpp"

class Client {
	public:
		Client(int clntfd);

		void	setInit(bool flag);
		void	setNickname(string nickname);
		void	setUsername(string username);
		bool	getInit();
		int 	getClntfd();
		string	getNickname();
		string 	getUsername();
	private:
		int		_clntfd;
		string 	_nickname;
		string 	_username;
		// bool 	_isOp;
		bool	_isInit;
};

#endif