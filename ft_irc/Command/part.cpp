#include "Command.hpp"

void Command::part(vector<string> token) {
	vector<Channel *>::iterator it;

	for (it = _chList.begin(); it != _chList.end(); it++) {
		if ((*it)->getChannelName() == token[1]) {
			vector<Client *> members = (*it)->getMemberList();
			for (int i = 0; i < (int)members.size(); i++) {
				string msg = ":" + _client->getNickname() + "!" 
					+ members[i]->getUsername() + "@127.0.0.1 PART :" + token[1] + "\n"; 
				if (send(members[i]->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
					perr("Error: send error");
				_logfile << "O " << msg;
			}
		}
	}
	_client->delChannel(token[1], false);
}