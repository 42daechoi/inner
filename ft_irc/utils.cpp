#include "header.hpp"

void noMemberChannel(vector<Channel *> &chList) {
	vector<Channel *>::iterator it = chList.begin();
	while (it != chList.end()) {
		if ((*it)->getMemberList().size() == 0) {
			delete *it;
			it = chList.erase(it);
		}
		else
			it++;
	}
}

void delChannelList(vector<Channel *> &chList, string clnt_nickname) {
	vector<Channel *>::iterator it;
	for (it = chList.begin(); it != chList.end(); it++) {
		(*it)->delInviteList(clnt_nickname);
		(*it)->delOperList(clnt_nickname);
	}
}

void printInput( ostream& logFile, string msg)
{
	logFile << "I " << msg;
	logFile.flush();
}

void printOutput( ostream& logFile, string msg)
{
	logFile << "O " << msg;
	logFile.flush();
}

void incorrectPassword(int clntfd, vector<struct pollfd> &vfds, vector<Client *> &clntList, int i) {
	close(clntfd);
	vfds.erase(vfds.begin() + i);
	delete clntList[i - 1];
	clntList.erase(clntList.begin() + i - 1);
}

void quitClient(int clntfd, vector<struct pollfd> &vfds, vector<Client *> &clntList, int i, vector<Channel *> &chList) {
	close(clntfd);
	vfds.erase(vfds.begin() + i);
	clntList[i - 1]->delAllChannel();
	noMemberChannel(chList);
	delChannelList(chList, clntList[i - 1]->getNickname());
	delete clntList[i - 1];
	clntList.erase(clntList.begin() + i - 1);
}

pollfd makePollfd(int fd) {
	struct pollfd poll;
	
	poll.fd = fd;
	poll.events = POLLIN;
	return poll;
}