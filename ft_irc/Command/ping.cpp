#include "Command.hpp"

void	Command::ping(vector<string> token)
{
	string	msg;

	msg = ":" + \
		token[1] + \
		" PONG " + \
		token[1] + \
		" :" + \
		token[1] +
		"\n";
	if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	printLog(msg);
}