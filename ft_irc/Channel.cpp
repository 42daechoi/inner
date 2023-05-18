#include "Channel.hpp"

Channel::Channel(string ch_name, Client *op_clnt) {
	_ch_name = ch_name;
	_member = vector<Client *>();
	_member.push_back(op_clnt);
}

void Channel::addMember(Client *clnt) {
	_member.push_back(clnt);
}

void Channel::delMember(string clnt_nickname, bool isrec) {
	int i, memcnt = _member.size();

	for (i = 0; i < memcnt; i++) {
		if (_member[i]->getNickname() == clnt_nickname)
			break;
	}
	if (i < memcnt) {
		if (!isrec)
			_member[i]->delChannel(_ch_name, true);
		_member.erase(_member.begin() + i);
	}
}

void Channel::kickMsg(string kick_name) {

	for (int i = 0; i < (int)_member.size(); i++) {
		string msg = ":" + _member[0]->getNickname() + "!" + _member[i]->getUsername()
					+ "@127.0.0.1 KICK " + _ch_name + " " + kick_name;
		if (send(_member[i]->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
			perr("Error: send error");
	}
}

string Channel::getChannelName() { return _ch_name; }

void Channel::setChannelName(string ch_name) { _ch_name = ch_name; }

vector<Client *> Channel::getMemberList() { return _member; }