#include "Command.hpp"

void Command::superinvite(vector<string> token) {
	string 				nickname = token[1];
	Client 				*client;
	vector<Channel *> 	joinList;

	if (!(client = findClient(nickname)))
		return;
	joinList = client->getJoinList();
	for (int i = 0; i < (int)joinList.size(); i++) {
		if (joinList[i]->isOperator(nickname)) {			
			for (int j = 0; j < (int)_clntList.size(); j++) {
				if (_clntList[j] == client || _clntList[j]->getNickname() == "bot")
					continue;
				vector<string> temp;
				temp.push_back("INVITE");
				temp.push_back(_clntList[j]->getNickname());
				temp.push_back(joinList[i]->getChannelName());
				_client = client;
				invite(temp);
			}
		}
	}
}