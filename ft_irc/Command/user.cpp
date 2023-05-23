#include "Command.hpp"

void	Command::user(vector<string> token)
{
	string msg = "";
	_client->setUsername(token[1]);
	if (_client->getNickname() != "" && _client->getInit() == false)
	{
		msg = makeWelcomeMsg();
		if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
			perr("Error: send error");
		else
			_client->setInit(true);
		printLog(msg);
	}
}