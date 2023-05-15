#include "Client.hpp"

Client::Client(int clntfd) : _nickname(""), _username(""), _isInit(false) {
	_clntfd = clntfd;
	_joinList = vector<Channel *>();
}

void Client::addChannel(Channel *ch) {
	for (int i = 0; i < (int)_joinList.size(); i++) {
		if (_joinList[i]->getChannelName() == ch->getChannelName())
			return;
	}
	_joinList.push_back(ch);
}

void Client::delChannel() {
	for (int i = 0; i < (int)_joinList.size(); i++) {
		_joinList[i]->delMember(_nickname);
	}
}

void	Client::setInit(bool flag) { _isInit = flag; }

void Client::setNickname(string nickname) { _nickname = nickname; }

void Client::setUsername(string username) { _username = username; }

bool	Client::getInit() { return _isInit; }

int Client::getClntfd() { return _clntfd; }

string Client::getNickname() { return _nickname; }

string Client::getUsername() { return _username; }

vector<Channel *> Client::getJoinList() { return _joinList; }

