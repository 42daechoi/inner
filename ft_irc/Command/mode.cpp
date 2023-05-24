#include "Command.hpp"

void Command::optionI(Channel *channel, char op_flag) {
	vector<Client *> 	members = channel->getMemberList();
	string 				msg;

	if (op_flag == '+' && !channel->getInviteOnly()) {
		channel->setInviteOnly(true);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), "MODE", channel->getChannelName(), "+i");
	}
	else if (op_flag == '-' && channel->getInviteOnly()) {
		channel->setInviteOnly(false);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), "MODE", channel->getChannelName(), "-i");
	}
}

void Command::optionT(Channel *channel, char op_flag) {
	vector<Client *> 	members = channel->getMemberList();
	string 				msg;

	if (op_flag == '+' && !channel->getTopicFlag()) {
		channel->setTopicFlag(true);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), "MODE", channel->getChannelName(), "+t");
	}
	else if (op_flag == '-' && channel->getTopicFlag()) {
		channel->setTopicFlag(false);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), "MODE", channel->getChannelName(), "-t");
	}
}


void Command::optionK(Channel *channel, char op_flag, string password) {
	vector<Client *> 	members = channel->getMemberList();
	string 				msg;

	if (op_flag == '+' && !channel->isPassMode()) {
		channel->setPassword(password);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), "MODE", channel->getChannelName() + " +k", password);
	}
	else if (op_flag == '-' && channel->isPassMode()) {
		channel->unsetPassword();
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), "MODE", channel->getChannelName() + " -k", password);
	}
}

void Command::optionO(Channel *channel, char op_flag, string nickname) {
	vector<Client *> 	members = channel->getMemberList();
	string 				msg;
	Client 				*client;

	if (!(client = findClient(nickname)))
		return ;
	if (op_flag == '+' && !channel->isOperator(nickname)) {
		channel->addOperList(client);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), "MODE", channel->getChannelName() + " +o", nickname);
	}
	else if (op_flag == '-' && channel->isOperator(nickname)) {
		channel->delOperList(nickname);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), "MODE", channel->getChannelName() + " -o", nickname);
	}
}

void Command::optionL(Channel *channel, char op_flag, vector<string> token) {
	vector<Client *> 	members = channel->getMemberList();
	string 				msg, limit_str;

	if (token.size() == 4)
		limit_str = token[3];
	if (op_flag == '+') {
		channel->setLimitNum(limit_str);
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), "MODE", channel->getChannelName() + " +l", limit_str);
	}
	else if (op_flag == '-') {
		channel->setLimitNum("0");
		for (int i = 0; i < (int)members.size(); i++)
			sendOptionMsg(members[i]->getClntfd(), "MODE", channel->getChannelName(), "-l");
	}
}

void Command::mode(vector<string> token) {
	string ch_name = token[1], option;
	Channel *channel;
	
	if (ch_name[0] != '#' || token.size() == 2)
		return;
	option = token[2];
	if (!(channel = findChannel(ch_name)) || !channel->isMember(_client->getNickname())) {
		sendCodeMsg(_client->getClntfd(), "403", _client->getNickname(), "No such channel");
		return;
	}
	if (!channel->isOperator(_client->getNickname())) {
		string opt(1, option[1]);
		sendCodeMsg(_client->getClntfd(), "482", ch_name, "You must have channel op access or above to set channel mode " + opt);
		return;
	}
	if (option[1] == 'i') optionI(channel, option[0]);
	else if (option[1] == 't') return optionT(channel, option[0]);
	else if (option[1] == 'k') return optionK(channel, option[0], token[3]);
	else if (option[1] == 'o') return optionO(channel, option[0], token[3]);
	else if (option[1] == 'l') return optionL(channel, option[0], token);
}