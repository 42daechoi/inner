#include "Command.hpp"

void	Command::shoutOutToChannel(Channel *channel) {
	string 				msg;
	vector<Client *>	members = channel->getMemberList();

	//각 멤버에게 메세지 전달 후 마지막에 입장한 사람에게 for문 아래 메세지를 추가로 전송해주는데 (memeber수 + 2개 전송) ret는 마지막 구문만 전달됨.(수정 필요)
	for (int i = 0; i < (int)members.size(); i++) {
			msg = ":" + _client->getNickname() +  
				+ "!" + members[i]->getUsername() +
				+ "@" + "127.0.0.1" + " JOIN :"
				+ channel->getChannelName() + "\n";
			if (send(members[i]->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
			_logfile << "O " << msg;
	}
	msg = ":irc.local 353 " + _client->getNickname()
		+ channel->getChannelName() + " :@";
	for (int i = 0; i < (int)members.size() - 1; i++)
		msg += members[i]->getNickname() + " ";
	msg += members[members.size() - 1]->getNickname() + "\n";
	if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	_logfile << "O " << msg;
	msg = ":irc.local 366 " + _client->getNickname()
		+ " " + channel->getChannelName()
		+ " :End of /NAMES list. \n";
	if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	_logfile << "O " << msg;
}

void Command::join(vector<string> token) {
	string 	ch_name;
	Channel *channel;

	if (token[1][0] != '#')
		perr("Error: tokenized error (#channelname)");
	ch_name = token[1];
	if (!(channel = findChannel(ch_name))) {
		channel = new Channel(ch_name, _client);
		_chList.push_back(channel);
	}
	else
		channel->addMember(_client);
	_client->addChannel(channel);
	shoutOutToChannel(channel);
}