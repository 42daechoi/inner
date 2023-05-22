#include "Command.hpp"

void Command::optionI(Channel *channel, char op_flag) {
	vector<Client *> 	members = channel->getMemberList();
	string 				msg;

	if (op_flag == '+' && !channel->getInviteOnly()) {
		channel->setInviteOnly(true);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), members[i]->getUsername(), "127.0.0.1", "MODE", channel->getChannelName(), "+i");
	}
	else if (op_flag == '-' && channel->getInviteOnly()) {
		channel->setInviteOnly(false);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), members[i]->getUsername(), "127.0.0.1", "MODE", channel->getChannelName(), "-i");
	}
}

void Command::optionT(Channel *channel, char op_flag) {
	vector<Client *> 	members = channel->getMemberList();
	string 				msg;

	if (op_flag == '+' && !channel->getTopicFlag()) {
		channel->setTopicFlag(true);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), members[i]->getUsername(), "127.0.0.1", "MODE", channel->getChannelName(), "+t");
	}
	else if (op_flag == '-' && channel->getTopicFlag()) {
		channel->setTopicFlag(false);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), members[i]->getUsername(), "127.0.0.1", "MODE", channel->getChannelName(), "-t");
	}
}


void Command::optionK(Channel *channel, char op_flag, string password) {
	vector<Client *> 	members = channel->getMemberList();
	string 				msg;

	if (op_flag == '+' && !channel->isPassMode()) {
		channel->setPassword(password);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), members[i]->getUsername(), "127.0.0.1", "MODE", channel->getChannelName() + " +k", password);
	}
	else if (op_flag == '-' && channel->isPassMode()) {
		channel->unsetPassword();
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), members[i]->getUsername(), "127.0.0.1", "MODE", channel->getChannelName() + " -k", password);
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
	else if (option[1] == 't') return optionT(channel, option[0]);
	else if (option[1] == 'k') return optionK(channel, option[0], token[3]);
	else if (option[1] == 'o') return ;
	else if (option[1] == 'l') return ;
}