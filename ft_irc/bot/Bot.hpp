#ifndef BOT_HPP
# define BOT_HPP

# include <string>
# include <iostream>
# include <sys/socket.h>

using namespace std;

class Bot {
	public:
		Bot(string msg);

		void 	sendToServer(int serverfd);
		string 	makeMsg();
	private:
		string 	_nickname;
		string 	_username;
		string 	_ip;
		string 	_msg;
};

#endif