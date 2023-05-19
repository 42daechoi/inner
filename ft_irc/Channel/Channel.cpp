#include "Channel.hpp"

Channel::Channel(string ch_name, Client *op_clnt) : _invite_only(false) {
	_ch_name = ch_name;
	_member = vector<Client *>();
	_inviteList = vector<Client *>();
	_member.push_back(op_clnt);
	_operList.push_back(op_clnt);
}

void Channel::addMember(Client *clnt) {
	if (_invite_only) {
		for (int i = 0; i < (int)_inviteList.size(); i++) {
			if (clnt == _inviteList[i])
				_member.push_back(clnt);
		}
	}
	else
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

bool Channel::inviteChannel(Client *clnt) {
	for (int i = 0; i < (int)_member.size(); i++) {
		if (clnt == _member[i])
			return false;
	}
	_inviteList.push_back(clnt);
	return true;
}

void Channel::delInviteList(string clnt_nickname) {
	int i, memcnt = _inviteList.size();

	for (i = 0; i < memcnt; i++) {
		if (_inviteList[i]->getNickname() == clnt_nickname)
			break;
	}
	if (i < memcnt)
		_inviteList.erase(_inviteList.begin() + i);
}

void Channel::delOperList(string clnt_nickname) {
	int i, memcnt = _operList.size();

	for (i = 0; i < memcnt; i++) {
		if (_operList[i]->getNickname() == clnt_nickname)
			break;
	}
	if (i < memcnt)
		_operList.erase(_operList.begin() + i);
}

void Channel::kickMsg(string kick_name) {

	for (int i = 0; i < (int)_member.size(); i++) {
		string msg = ":" + _member[0]->getNickname() + "!" + _member[i]->getUsername()
					+ "@127.0.0.1 KICK " + _ch_name + " " + kick_name + "\n";
		if (send(_member[i]->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
			perr("Error: send error");
	}
}

bool Channel::isOperator(string clnt_nickname) {
	for (int i = 0; i < (int)_operList.size(); i++) {
		if (clnt_nickname == _operList[i]->getNickname())
			return true;
	}
	return false;
}

bool Channel::isMember(string clnt_nickname) {
	for (int i = 0; i < (int)_member.size(); i++) {
		if (clnt_nickname == _member[i]->getNickname())
			return true;
	}
	return false;
}


string Channel::getChannelName() { return _ch_name; }

void Channel::setChannelName(string ch_name) { _ch_name = ch_name; }

void Channel::setInviteOnly(bool flag) { _invite_only = flag; }

vector<Client *> Channel::getOperList() { return _operList; }

vector<Client *> Channel::getMemberList() { return _member; }