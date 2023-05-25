#include "Command.hpp"

void	Command::shoutOutToChannel(Channel *channel) {
	string 				msg;
	vector<Client *>	members = channel->getMemberList();

	for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), "JOIN", "", channel->getChannelName());
	msg = ":irc.local 353 " + _client->getNickname() + " "
		+ channel->getChannelName() + " :@";
	for (int i = 0; i < (int)members.size() - 1; i++)
		msg += members[i]->getNickname() + " ";
	msg += members[members.size() - 1]->getNickname() + "\n";
	if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	printLog(msg);
	sendCodeMsg(_client->getClntfd(), "366", channel->getChannelName(), "End of /NAMES list.\n");
}

void Command::join(vector<string> token) {
	string 	ch_name;
	Channel *channel;
	bool 	joinflag = true;

	if (token[1][0] != '#')
		perr("Error: tokenized error (#channelname)");
	ch_name = token[1];
	if (!(channel = findChannel(ch_name))) {
		channel = new Channel(ch_name, _client, _logfile);
		_chList.push_back(channel);
		_client->addChannel(channel);
	}
	else {
		string password = "";
		if (token.size() == 3) password = token[2]; 
		if ((joinflag = channel->addMember(_client, password)))
			_client->addChannel(channel);
	}
	if (joinflag)
		shoutOutToChannel(channel);
}