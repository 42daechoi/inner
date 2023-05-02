#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "header.hpp"
# include "Channel.hpp"

class Channel;

class Client {
	public:
		Client(int clntfd);

		void 	addChannel(Channel ch);

		void	setInit(bool flag);
		void	setNickname(string nickname);
		void	setUsername(string username);
		bool	getInit();
		int 	getClntfd();
		string	getNickname();
		string 	getUsername();
	private:
		int					_clntfd;
		string 				_nickname;
		string 				_username;
		vector<Channel>		_chList;
		bool				_isInit;
};

#endif