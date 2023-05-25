#include "Command.hpp"

Channel *Command::findSuperChannel() {
	if (_chList.size() <= 0)
		return NULL;
	Channel *superch = _chList[0];
	for (int i = 0; i < (int)_chList.size(); i++) {
		if (superch->getMemberList().size() < _chList[i]->getMemberList().size())
			superch = _chList[i];
	}
	return superch;
}

void Command::superjoin(vector<string> token) {
	string 	nickname = token[1];
	Client 	*client;
	Channel *superch;

	if (!(client = findClient(nickname)))
		return;
	if (!(superch = findSuperChannel())) {
		sendOptionMsg(client->getClntfd(), "PRIVMSG", client->getNickname(), "Channel list is empty");
		return;
	}
	vector<string> temp;
	temp.push_back("JOIN");
	temp.push_back(superch->getChannelName());
	_client = client;
	join(temp);
}