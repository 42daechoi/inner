#include "Command.hpp"

Command::Command(string data, Client &client) : _client(client), _server("irc.local") {
	char *ptr = strtok((char *)data.c_str(), " \t");
	while (ptr != NULL)
	{
		_cmd.push_back(string(ptr));
		ptr = strtok(NULL, " \t");
	}
}

void Command::printCommand() {
	for (vector<string>::iterator it = _cmd.begin(); it != _cmd.end(); it++) {
		cout << "[" << *it << "] ";
	}
	cout << "\n";
}

string	Command::makeWelcomeMsg()
{
	string msg = ":" \
				+ _server \
				+ " 001 " \
				+ _client.getNickname() \
				+ " :Welcome to the Localnet IRC Network " \
				+ _client.getNickname() \
				+ "!" \
				+ _client.getUsername() \
				+ "127.0.0.1\n";
	return (msg);
}

void	Command::nick()
{
	string msg;

	_client.setNickname(_cmd[1]);
	if (_client.getUsername() != "" && _client.getInit() == false)
	{
		msg = makeWelcomeMsg();
		if (send(_client.getClntfd(), msg.c_str(), msg.length(), 0) == -1)
			perr("Error: send error");
		else
			_client.setInit(true);
	}
}

void Command::user()
{
	string msg;

	_client.setUsername(_cmd[1]);
	if (_client.getNickname() != "" && _client.getInit() == false)
	{
		msg = makeWelcomeMsg();
		if (send(_client.getClntfd(), msg.c_str(), msg.length(), 0) == -1)
			perr("Error: send error");
		else
			_client.setInit(true);
	}
}

void Command::execute() {
	if (_cmd[0] == "JOIN")	return;
	else if (_cmd[0] == "KICK") return;
	else if (_cmd[0] == "MODE") return;
	else if (_cmd[0] == "PASS") return;
	else if (_cmd[0] == "PING") return;
	else if (_cmd[0] == "QUIT") return;
	else if (_cmd[0] == "NICK")
		nick();
	else if (_cmd[0] == "USER")
		user();
	else if (_cmd[0] == "PRIVMSG") return ;
	// else
	// 	cout << "Error: command execute\n";
}

vector<string> Command::getCmd() {
	return _cmd;
}