#include "Command.hpp"

void Command::who(vector<string> token) {
	Channel 	*channel = findChannel(token[1]);
	string		msg;
	
	for (int i = 0; i < (int)channel->getMemberList().size(); i++) {
		msg = ":irc.local 352 " + _client->getNickname() + " "
			+ token[1] + " " + _client->getUsername() + " " + _client->getIp() + " irc.local "
			+ channel->getMemberList()[i]->getNickname() + " H";
		if (i == 0) msg += "@";
		msg += (" :0 " + channel->getMemberList()[i]->getNickname()) + "\n";
		if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
			perr("Error: send error");
		printLog(msg);
	}
	msg = ":irc.local 315 " + _client->getNickname() + " :End of /WHO list.\n";
	if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	printLog(msg);
}