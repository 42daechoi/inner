#include "Command.hpp"

void Command::optionI(Channel *channel, char op_flag) {
	vector<Client *> 	members = channel->getMemberList();
	string 				msg;

	if (op_flag == '+') {
		channel->setInviteOnly(true);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), _client->getUsername(), "127.0.0.1", "MODE", channel->getChannelName(), "+i");
	}
	else if (op_flag == '-') {
		channel->setInviteOnly(false);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), _client->getUsername(), "127.0.0.1", "MODE", channel->getChannelName(), "-i");
	}
}

void Command::mode(vector<string> token) {
	string ch_name = token[1], option = token[2];
	Channel *channel;
	
	if (ch_name[0] != '#' || option == "")
		return;
	if (!(channel = findChannel(ch_name)) || !channel->isMember(_client->getNickname())) {
		sendCodeMsg(_client->getClntfd(), "403", _client->getNickname(), "No such channel");
		return ;
	}
	if (!channel->isOperator(_client->getNickname())) {
		string opt(1, option[1]);
		sendCodeMsg(_client->getClntfd(), "482", ch_name, "You must have channel op access or above to set channel mode " + opt);
		return;
	}
	if (option[1] == 'i') optionI(channel, option[0]);
	else if (option[1] == 't') return ;
	else if (option[1] == 'k') return ;
	else if (option[1] == 'o') return ;
	else if (option[1] == 'l') return ;
}