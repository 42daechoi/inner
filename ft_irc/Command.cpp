#include "Command.hpp"

Command::Command(string data, Client &client) : _client(client) {
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

void Command::execute() {
	if (_cmd[0] == "JOIN")	return;
	else if (_cmd[0] == "KICK") return;
	else if (_cmd[0] == "MODE") return;
	else if (_cmd[0] == "PASS") return;
	else if (_cmd[0] == "PING") return;
	else if (_cmd[0] == "QUIT") return;
	else if (_cmd[0] == "NICK")
		_client.setNickname(_cmd[1]);
	else if (_cmd[0] == "USER")
		_client.setUsername(_cmd[1]);
	else if (_cmd[0] == "PRIVMSG") return ;
	else
		cout << "Error: command execute\n";
}

vector<string> Command::getCmd() {
	return _cmd;
}