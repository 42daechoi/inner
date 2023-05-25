#include "Bot.hpp"

Bot::Bot(string msg) {
	int i, j;

	i = msg.find("!");
	_nickname = msg.substr(1, i - 1);
	j = msg.find("@");
	_username = msg.substr(i + 1, j - i - 1);
	i = msg.find(" ");
	_ip = msg.substr(j + 1, i - j);
	i = msg.find(":", 2);
	_msg = msg.substr(i + 1, msg.length() - i);

	_msg.erase(0, _msg.find_first_not_of(" \n\t"));
	_msg.erase(_msg.find_last_not_of(" \n\t") + 1);
}

void Bot::sendToServer(int serverfd) {
	string msg = makeMsg();
	if (send(serverfd, msg.c_str(), msg.length(), 0) == -1) {
		cout << "Error: send error\n";
		exit(1);
	}
}

string Bot::makeMsg() {
	string msg;

	if (_msg == "help")
		msg = "PRIVMSG " + _nickname + " :<COMMAND LIST> SUPERINVITE\n";
	else if (_msg == "superinvite")
		msg = "SUPERINVITE " + _nickname + "\n";
	else
		msg = "PRIVMSG " + _nickname + " :There is no matching command. Please send me a help message\n";
	return msg;
}