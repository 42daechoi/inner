#include "Command.hpp"

void Command::invite(vector<string> token) {
	string 	nickname = token[1], ch_name = token[2], msg;
	Channel *channel;
	Client 	*invite_clnt;
	
	if (!(channel = findChannel(ch_name)) || !channel->isMember(_client->getNickname())) {
		sendCodeMsg(_client->getClntfd(), "403", nickname, "No such channel");
		return ;
	}
	if (!channel->isOperator(_client->getNickname())) {
		youAreNotOp(ch_name);
		return ;
	}
	if (!(invite_clnt = findClient(nickname))) { 
		sendCodeMsg(_client->getClntfd(), "401", nickname, "No such nick");
		return ;
	}
	if (!channel->inviteChannel(invite_clnt))
		sendCodeMsg(_client->getClntfd(), "443", invite_clnt->getNickname() + " " + ch_name, "is already on channel");
	else {
		sendOptionMsg(invite_clnt->getClntfd(), "INVITE", nickname, ch_name);
		sendCodeMsg(_client->getClntfd(), "341", invite_clnt->getNickname(), ch_name);
		vector<Client *> members = channel->getMemberList();
		for (int i = 0; i < (int)members.size(); i++) {
			if (members[i] != _client) {
				string msg = ":irc.local NOTICE " + channel->getChannelName() + " :*** "
					+ _client->getNickname() + " invited " + nickname + " into the channel\n";
				if (send(members[i]->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
					perr("Error: send error");
			}
		}
	}
}
