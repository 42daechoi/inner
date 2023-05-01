#include "Client.hpp"

Client::Client(int clntfd) : _nickname(""), _username("") {
	_clntfd = clntfd;
}

void Client::setNickname(string nickname) { _nickname = nickname; }

void Client::setUsername(string username) { _username = username; }

string Client::getNickname() { return _nickname; }

string Client::getUsername() { return _username; }

