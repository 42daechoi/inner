#include "Command.hpp"

void Command::part(vector<string> token) {
	vector<Client *>	members;
	Channel 			*channel;

	if (!(channel = findChannel(token[1])))
		return ;
	members = channel->getMemberList();
	for (int i = 0; i < (int)members.size(); i++)
		sendOptionMsg(members[i]->getClntfd(), "PART", "", token[1]);
	channel->delOperList(_client->getNickname());
	_client->delChannel(token[1], false);
}