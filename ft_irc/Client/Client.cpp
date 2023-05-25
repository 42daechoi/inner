#include "Client.hpp"

Client::Client(int clntfd) : _nickname(""), _username(""), _isInit(false), _password(""), _msg("") {
	struct sockaddr_in	clnt_addr;
	socklen_t			ca_size = sizeof(clnt_addr);
	
	if (getsockname(clntfd, (struct sockaddr*)&clnt_addr, &ca_size) == -1)
		cout << "Failed to get local socket address" << endl;
	_ip = inet_ntoa(clnt_addr.sin_addr);
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

void Client::delChannel(string ch_name, bool isrec) {
	for (int i = 0; i < (int)_joinList.size(); i++) {
		if (_joinList[i]->getChannelName() == ch_name) {
			if (!isrec)
				_joinList[i]->delMember(_nickname, true);
			_joinList.erase(_joinList.begin() + i);
		}
	}
}

void Client::delAllChannel() {
	for (int i = 0; i < (int)_joinList.size(); i++) 
		_joinList[i]->delMember(_nickname, true);
}

void	Client::addMsg(string msg) {
	_msg += msg;
}

void	Client::setInit(bool flag) { _isInit = flag; }

void Client::setNickname(string nickname) { _nickname = nickname; }

void Client::setUsername(string username) { _username = username; }

void Client::setPassword(string password) { _password = password; }

void Client::setMsg(string msg) { _msg = msg; }

bool	Client::getInit() { return _isInit; }

int Client::getClntfd() { return _clntfd; }

string Client::getNickname() { return _nickname; }

string Client::getUsername() { return _username; }

vector<Channel *> Client::getJoinList() { return _joinList; }

string Client::getPassword() { return _password; }

string	Client::getIp() { return _ip; }

string	Client::getMsg() { return _msg; }