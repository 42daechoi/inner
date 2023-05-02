#include "Channel.hpp"

Channel::Channel(string ch_name, Client op_clnt) {
	_ch_name = ch_name;
	_member.push_back(op_clnt);
}

void Channel::addMember(Client clnt) {
	_member.push_back(clnt);
}

string Channel::getChannelName() { return _ch_name; }

void Channel::setChannelName(string ch_name) { _ch_name = ch_name; }

vector<Client> Channel::getMemberList() { return _member; }