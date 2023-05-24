#include "Command.hpp"

void Command::msgSendToClient(vector<string> token) {
	vector<Client *>::iterator 	it;
	string 						msg, rcv_name = token[1];

	for (it = _clntList.begin(); it != _clntList.end(); it++) {
		if ((*it)->getNickname() == rcv_name) {
			msg = ":" + _client->getNickname() + "!" + _client->getUsername()
				+ "@" + _client->getIp() + " PRIVMSG " + rcv_name + " ";
			for (int i = 2; i < (int)token.size() - 1; i++)
				msg += (token[i] + " ");
			msg += (token[token.size() - 1] + "\n");
			if (send((*it)->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
			printLog(msg);
		}
	}
}

void Command::msgSendToChannel(vector<string> token) {
	vector<Channel *>::iterator	it;
	string 						msg = "", rcv_channel = token[1];

	for (it = _chList.begin(); it != _chList.end(); it++) {
		if ((*it)->getChannelName() == rcv_channel) {
			vector<Client *> members = (*it)->getMemberList();
			if(!((*it)->isMember(_client->getNickname()))) return;
			for (int i = 0; i < (int)members.size(); i++) {
				if (members[i] == _client)
					continue;
				msg = ":" + _client->getNickname() + "!" + _client->getUsername()
					+ "@" + _client->getIp() + " PRIVMSG " + rcv_channel + " ";
				for (int i = 2; i < (int)token.size() - 1; i++)
					msg += (token[i] + " ");
				msg += (token[token.size() - 1] + "\n");
				if (send(members[i]->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
					perr("Error: send error");
				printLog(msg);
			}
		}
	}
}

void	Command::privmsg(vector<string> token) {
	if (token[1][0] == '#')
		msgSendToChannel(token);
	else
		msgSendToClient(token);
}