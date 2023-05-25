#include "Command.hpp"

string	Command::makeChangeNickMsg(string cmd)
{
	string msg = ":" \
				+ _client->getNickname() \
				+ "!" \
				+ _client->getUsername() \
				+ "@" \
				+ _client->getIp() \
				+ " NICK :";
	if (isSameNick(cmd))
		cmd = cmd + "_";
	msg += cmd + "\n";
	_client->setNickname(cmd);
	return (msg);
}

int		Command::isSameNick(string cmd)
{
	vector<Client *>::iterator it;

	for (it = _clntList.begin(); it != _clntList.end(); it++)
		if ((*it)->getNickname() == cmd)
			return (1);
	return (0);
}

void	Command::nick(vector<string> token)
{
	string msg = "";

	if (_client->getInit() == false)
	{
		if (isSameNick(token[1]))
			token[1] = token[1] + "_";
		_client->setNickname(token[1]);
		if (_client->getUsername() != "")
		{
			msg = makeWelcomeMsg();
			if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
			else
				_client->setInit(true);
			printLog(msg);
		}
	}
	else
	{
		if (token[1] != _client->getNickname())
		{
			msg = makeChangeNickMsg(token[1]);
			if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
			printLog(msg);
		}
	}
}