#include "Command.hpp"

void Command::sendtoChannelTopic(Channel *channel, string msg) {
	vector<Client *> members = channel->getMemberList();

	channel->setTopic(msg);
	for (int i = 0; i < (int)members.size(); i++)
		sendOptionMsg(members[i]->getClntfd(), "TOPIC", channel->getChannelName(), msg);
}

void Command::topic(vector<string> token) {
	Channel *channel;
	string	msg;
	int 	i;

	for (i = 2; i < (int)token.size() - 1; i++)
		msg += (token[i] + " ");
	msg += token[i];
	msg.erase(0, 1);
	if (!(channel = findChannel(token[1]))) {
		sendCodeMsg(_client->getClntfd(), "403", _client->getNickname(), "No such channel");
		return ;
	}
	if ((channel->getTopicFlag() && channel->isOperator(_client->getNickname())) || !channel->getTopicFlag()) {
		sendtoChannelTopic(channel, msg);
		return ;
	}
	sendCodeMsg(_client->getClntfd(), "482", channel->getChannelName(), "You do not have access to change the topic on this channel");
}