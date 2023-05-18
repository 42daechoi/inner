#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "header.hpp"
# include "Channel.hpp"

class Channel;

class Client {
	public:
		Client(int clntfd);

		void 				addChannel(Channel *ch);
		void 				delChannel(string ch_name, bool isrec);
		void 				delAllChannel();

		void				setInit(bool flag);
		void				setNickname(string nickname);
		void				setUsername(string username);
		void 				setPassword(string password);
		bool				getInit();
		int 				getClntfd();
		string				getNickname();
		string 				getUsername();
		vector<Channel *>	getJoinList();
		string 				getPassword();
	private:
		int					_clntfd;
		string 				_nickname;
		string 				_username;
		vector<Channel *>	_joinList;
		bool				_isInit;
		string 				_password;
};

#endif