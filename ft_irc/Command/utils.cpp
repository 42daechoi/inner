#include "Command.hpp"

void Command::sendOptionMsg(int fd, string option, string target, string info) {
	string msg = ":" + _client->getNickname() + "!" + _client->getUsername() + "@" + _client->getIp() + " " + option;
	if (target != "")
		msg += (" " + target);
	msg += + " :" + info + "\n";
	if (send(fd, msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	printLog(msg);
}

void Command::sendCodeMsg(int fd, string code, string target, string info) {
	string msg = ":irc.local " + code + " " + _client->getNickname() + " " + target + " :" + info + "\n";
	if (send(fd, msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	printLog(msg);
}

Channel *Command::findChannel(string ch_name) {
	for (int i = 0; i < (int)_chList.size(); i++) {
		if (ch_name == _chList[i]->getChannelName())
			return _chList[i];
	}
	return NULL;
}

Client *Command::findClient(string nickname) {
	for (int i = 0; i < (int)_clntList.size(); i++) {
		if (nickname == _clntList[i]->getNickname())
			return _clntList[i];
	}
	return NULL;
}

int Command::findSharp() {
	for (int i = 0; i < (int)_cmd.size(); i++) {
		if (_cmd[i][0] == '#')
			return i;
	}
	return -1;
}

string	Command::makeWelcomeMsg()
{
	string msg = ":" \
				+ _server \
				+ " 001 " \
				+ _client->getNickname() \
				+ " :Welcome to the Localnet IRC Network " \
				+ _client->getNickname() \
				+ "!" \
				+ _client->getUsername() \
				+ _client->getIp() + "\n";
	return (msg);
}

void Command::youAreNotOp(string ch_name) {
	string msg;
	msg = ":irc.local 482" + _client->getNickname() + " " + ch_name + " :You must be a channel operator\n";
	if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	printLog(msg);
}

void	Command::printLog(string msg)
{
	_logfile << "O " << msg;
	_logfile.flush();
}
