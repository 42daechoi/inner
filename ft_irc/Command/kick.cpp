#include "Command.hpp"

int Command::findChannelIdx(string ch_name) {
	string	origin;
	string	compare;

	origin = ch_name;
	for (int i = 0; i < (int)_chList.size(); i++) {
		compare = _chList[i]->getChannelName();
		if (origin == compare)
			return i;
	}
	return -1;
}


void kick_member(vector<Client *> &members, string kick_nick) {
	int i;

	for (i = 0; i < (int)members.size(); i++) {
		if (members[i]->getNickname() == kick_nick)
			break;
	}
	if (i < (int)members.size())
		members.erase(members.begin() + i);
}

void kick_channel(vector<Channel *> &channelList, string kick_channel) {
	int i;

	for (i = 0; i < (int)channelList.size(); i++) {
		if (channelList[i]->getChannelName() == kick_channel)
			break;
	}
	if (i < (int)channelList.size())
		channelList.erase(channelList.begin() + i);
}

void Command::kick(vector<string> token) {
	int ch_idx;
	
	if (token[1][0] != '#')
		perr("Error: tokenized error (#channelname)");
	if ((ch_idx = findChannelIdx(token[1])) == -1)
		perr("Error: cannot find channel (KICK)");
	if (_client->getNickname() != _chList[ch_idx]->getMemberList()[0]->getNickname())
		youAreNotOp(token[1]);
	else {
		_chList[ch_idx]->kickMsg(token[2]);
		_chList[ch_idx]->delMember(token[2], false);
	}
}