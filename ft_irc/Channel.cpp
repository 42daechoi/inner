#include "Channel.hpp"

Channel::Channel(string ch_name, Client *op_clnt) {
	_ch_name = ch_name;
	_member = vector<Client *>();
	_member.push_back(op_clnt);
}

void Channel::addMember(Client *clnt) {
	_member.push_back(clnt);
}

void Channel::delMember(string clnt_nickname) {
	int i, memcnt = _member.size();

	for (i = 0; i < memcnt; i++) {
		if (_member[i]->getNickname() == clnt_nickname)
			break;
	}
	if (i < memcnt)
		_member.erase(_member.begin() + i);
}

string Channel::getChannelName() { return _ch_name; }

void Channel::setChannelName(string ch_name) { _ch_name = ch_name; }

vector<Client *> Channel::getMemberList() { return _member; }