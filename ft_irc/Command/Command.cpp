#include "Command.hpp"

Command::Command(string data, Client *client, vector<Client *> &clntList, vector<Channel *> &chList, string cpass, ostream& logfile) : _chList(chList), _clntList(clntList), _client(client), _server("irc.local"), _cpass(cpass), _logfile(logfile) {
	char *ptr = strtok((char *)data.c_str(), "\n");
	while (ptr != NULL)
	{
		_cmd.push_back(string(ptr));
		ptr = strtok(NULL, "\n");
	}
}

void Command::printCommand() {
	for (vector<string>::iterator it = _cmd.begin(); it != _cmd.end(); it++) {
		cout << "[" << *it << "] ";
	}
	cout << "\n";
}


vector<string> Command::parseExecute(const string& com) {
    vector<string> token;
    std::istringstream iss(com);
    string tokenStr;
    while (iss >> tokenStr) {
        tokenStr.erase(0, tokenStr.find_first_not_of(" \t\n"));
        tokenStr.erase(tokenStr.find_last_not_of(" \t\n") + 1);
        token.push_back(tokenStr);
    }
    return token;
}

int	Command::execute() {
	vector<string>	token;
	string	msg;

	for (vector<string>::iterator iter = _cmd.begin(); iter != _cmd.end(); iter++)
	{
		token = parseExecute(*iter);
		if (token[0] == "JOIN") join(token);
		else if (token[0] == "KICK") kick(token);
		else if (token[0] == "PART") part(token);
		else if (token[0] == "PASS") {
			if (pass(token) == -1) return -1;
		}
		else if (token[0] == "PING") ping(token);
		else if (token[0] == "NICK") nick(token);
		else if (token[0] == "USER") user(token);
		else if (token[0] == "PRIVMSG") privmsg(token);
		else if (token[0] == "WHO") who(token);
		else if (token[0] == "INVITE") invite(token);
		else if (token[0] == "MODE") mode(token);
		else if (token[0] == "TOPIC") topic(token);
		else if (token[0] == "SUPERINVITE") superinvite(token);
	}
	if (_client->getNickname() != "" && _client->getUsername() != "" && _client->getPassword() == "") {
		msg = "please type password\n";
		if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1) {
			perr("Error: send error");
		}
		printLog(msg);
		return -1;
	}
	return 0;
}

vector<string> Command::getCmd() {
	return _cmd;
}