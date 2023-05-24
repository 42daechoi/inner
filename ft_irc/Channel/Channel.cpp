#include "Channel.hpp"

Channel::Channel(string ch_name, Client *op_clnt, ostream& logfile) : _invite_only(false), _topic_flag(true), _topic(""), _limit_number(0), _logfile(logfile) {
	_ch_name = ch_name;
	_member = vector<Client *>();
	_inviteList = vector<Client *>();
	_member.push_back(op_clnt);
	_operList.push_back(op_clnt);
}

void Channel::sendTopic(Client *clnt) {
	if (_topic != "")
		sendCodeMsg(clnt->getClntfd(), "332", clnt->getNickname(), _ch_name, _topic);
}

bool Channel::isInvitee(Client *clnt) {
	bool joinflag = false;
	for (int i = 0; i < (int)_inviteList.size(); i++) {
		if (clnt == _inviteList[i]) {
			_member.push_back(clnt);
			joinflag = true;
		}
	}
	if (!joinflag)
		sendCodeMsg(clnt->getClntfd(), "473", clnt->getNickname(), _ch_name, "Cannot join channel (invite only)");
	return joinflag;
}

bool Channel::addMember(Client *clnt, string password) {
	bool joinflag = false;

	if (_limit_number != 0) {
		if ((int)_member.size() >= _limit_number) {
			sendCodeMsg(clnt->getClntfd(), "471", clnt->getNickname(), _ch_name, "Cannot join channel (channel is full)");
			return false;
		}
	}
	if (_invite_only)
		joinflag = isInvitee(clnt);
	else {
		if (_password != "" && _password != password) {
			joinflag = false;
			sendCodeMsg(clnt->getClntfd(), "475", clnt->getNickname(), _ch_name, "Cannot join channel (incorrect channel key)");
		}
		else {
			_member.push_back(clnt);
			joinflag = true;
		}
	}
	if (joinflag) {
		sendTopic(clnt);
		delInviteList(clnt->getNickname());
	}
	return joinflag;
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

void Channel::addOperList(Client *clnt) {
	_operList.push_back(clnt);
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

void Channel::kickMsg(Client *clnt, string kick_name) {
	for (int i = 0; i < (int)_member.size(); i++) {
		string msg = ":" + clnt->getNickname() + "!" + clnt->getUsername()
					+ "@" + clnt->getIp() + " KICK " + _ch_name + " " + kick_name + "\n";
		if (send(_member[i]->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
			perr("Error: send error");
		_logfile << "O " << msg;
		_logfile.flush();
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

bool Channel::isPassMode() {
	if (_password == "")
		return false;
	return true;
}

string Channel::getChannelName() { return _ch_name; }

void Channel::setChannelName(string ch_name) { _ch_name = ch_name; }

void Channel::setInviteOnly(bool flag) { _invite_only = flag; }

void Channel::setTopicFlag(bool flag) { _topic_flag = flag; }

void Channel::setTopic(string topic) { _topic = topic; }

void Channel::setPassword(string password) { _password = password; }

void Channel::setLimitNum(string limit_str) { 
	istringstream iss(limit_str);
	int ln;

	iss >> ln;
	_limit_number = ln;
}

void Channel::unsetPassword() { _password = ""; }

vector<Client *> Channel::getOperList() { return _operList; }

vector<Client *> Channel::getMemberList() { return _member; }

bool Channel::getInviteOnly() { return _invite_only; }

bool Channel::getTopicFlag() { return _topic_flag; }

void Channel::sendCodeMsg(int fd, string code, string nickname, string target, string info) {
	string msg = ":irc.local " + code + " " + nickname + " " + target + " :" + info + "\n";
	if (send(fd, msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	_logfile << "O " << msg;
	_logfile.flush();
}

