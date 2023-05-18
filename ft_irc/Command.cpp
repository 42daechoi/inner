#include "Command.hpp"

Command::Command(string data, Client *client, vector<Client *> &clntList, vector<Channel *> &chList) : _chList(chList), _clntList(clntList), _client(client), _server("irc.local") {
	//생성자에서의 파싱 기준을 \n으로만 하고 execute함수에서 나머지 파싱을 하는거로
	char *ptr = strtok((char *)data.c_str(), "\n");
	while (ptr != NULL)
	{
		_cmd.push_back(string(ptr));
		ptr = strtok(NULL, "\n");
	}
}

void Command::printCommand() {
	for (vector<string>::iterator it = _cmd.begin(); it != _cmd.end(); it++) {
		cout << "[" << *it << "] ";
	}
	cout << "\n";
}

string	Command::makeWelcomeMsg()
{
	string msg = ":" \
				+ _server \
				+ " 001 " \
				+ _client->getNickname() \
				+ " :Welcome to the Localnet IRC Network " \
				+ _client->getNickname() \
				+ "!" \
				+ _client->getUsername() \
				+ "127.0.0.1\n";
	return (msg);
}

string	Command::makeChangeNickMsg(string cmd)
{
	string msg = ":" \
				+ _client->getNickname() \
				+ "!" \
				+ _client->getUsername() \
				+ "@127.0.0.1 " \
				+ "NICK :";
	if (isSameNick(cmd))
		cmd = cmd + "_";
	msg += cmd + "\n";
	_client->setNickname(cmd);
	return (msg);
}

int		Command::isSameNick(string cmd)
{
	vector<Client *>::iterator it;
	for (it = _clntList.begin(); it != _clntList.end(); it++)
		if ((*it)->getNickname() == cmd)
			return (1);
	return (0);
}

string	Command::nick(vector<string> token)
{
	string msg = "";
	if (_client->getInit() == false)//최초 생성시
	{
		if (isSameNick(token[1]))
			token[1] = token[1] + "_";
		_client->setNickname(token[1]);
		if (_client->getUsername() != "")//NICK, USER완성시
		{
			msg = makeWelcomeMsg();
			if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
			else
				_client->setInit(true);
		}
	}
	else//이미 생성 이력 있고 NICK바꿀시
	{
		if (token[1] != _client->getNickname())//원래 닉네임이랑 같으면 아무 동작 안함
		{
			msg = makeChangeNickMsg(token[1]); //이 함수 내부에서 set이랑 중복검사함
			if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
		}
	}
	return (msg);
}

string Command::user(vector<string> token)
{
	string msg = "";
	_client->setUsername(token[1]);
	if (_client->getNickname() != "" && _client->getInit() == false)
	{
		msg = makeWelcomeMsg();
		cout << "in user msg" << msg << endl;
		if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
			perr("Error: send error");
		else
			_client->setInit(true);
	}
	return (msg);
}

int Command::findSharp() {
	for (int i = 0; i < (int)_cmd.size(); i++) {
		if (_cmd[i][0] == '#')
			return i;
	}
	return -1;
}

Channel *Command::findChannel(string ch_name) {
	for (int i = 0; i < (int)_chList.size(); i++) {
		if (ch_name == _chList[i]->getChannelName())
			return _chList[i];
	}
	return NULL;
}

string	Command::shoutOutToChannel(Channel *channel) {
	string 				msg;
	string				ret;
	vector<Client *>	members = channel->getMemberList();

	//각 멤버에게 메세지 전달 후 마지막에 입장한 사람에게 for문 아래 메세지를 추가로 전송해주는데 (memeber수 + 2개 전송) ret는 마지막 구문만 전달됨.(수정 필요)
	for (int i = 0; i < (int)members.size(); i++) {
			msg = ":" + _client->getNickname() +  
				+ "!" + members[i]->getUsername() +
				+ "@" + "127.0.0.1" + " JOIN :"
				+ channel->getChannelName() + "\n";
			if (send(members[i]->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
			ret = msg;
	}
	msg = ":irc.local 353 " + _client->getNickname()
		+ channel->getChannelName() + " :@";
	for (int i = 0; i < (int)members.size() - 1; i++)
		msg += members[i]->getNickname() + " ";
	msg += members[members.size() - 1]->getNickname() + "\n";
	if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	ret += msg;
	msg = ":irc.local 366 " + _client->getNickname()
		+ " " + channel->getChannelName()
		+ " :End of /NAMES list. \n";
	if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	ret += msg;
	return (ret);
}

string Command::join(vector<string> token) {
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
	return (shoutOutToChannel(channel));
}

string	Command::ping(vector<string> token)
{
	string	msg;

	msg = ":" + \
		token[1] + \
		" PONG " + \
		token[1] + \
		" :" + \
		token[1] +
		"\n";
	if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	return (msg);
}

vector<string>	Command::parseExecute(string com)
{
	vector<string>	token;

	char *ptr = strtok((char *)com.c_str(), " \t\n");
	while (ptr != NULL)
	{
		token.push_back(string(ptr));
		ptr = strtok(NULL, " \t\n");
	}
	return (token);
}

void kick_member(vector<Client *> &members, string kick_nick) {
	int i;

	for (i = 0; i < (int)members.size(); i++) {
		if (members[i]->getNickname() == kick_nick)
			break;
	}
	if (i < (int)members.size())
		members.erase(members.begin() + i);
}

void kick_channel(vector<Channel *> &channelList, string kick_channel) {
	int i;

	for (i = 0; i < (int)channelList.size(); i++) {
		if (channelList[i]->getChannelName() == kick_channel)
			break;
	}
	if (i < (int)channelList.size())
		channelList.erase(channelList.begin() + i);
}

int Command::findChannelIdx(string ch_name) {
	string	origin;
	string	compare;

	origin = ch_name;
	for (int i = 0; i < (int)_chList.size(); i++) {
		compare = _chList[i]->getChannelName();
		if (origin == compare)
			return i;
	}
	return -1;
}

void Command::youAreNotOp(string ch_name) {
	string msg;
	msg = ":irc.local 482" + _client->getNickname() + " " + ch_name + " :You must be a channel operator";
	if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
}

string Command::kick(vector<string> token) {
	int ch_idx;
	
	if (token[1][0] != '#')
		perr("Error: tokenized error (#channelname)");
	if ((ch_idx = findChannelIdx(token[1])) == -1)
		perr("Error: cannot find channel (KICK)");
	if (_client->getNickname() != _chList[ch_idx]->getMemberList()[0]->getNickname())
		youAreNotOp(token[1]);
	else {
		_chList[ch_idx]->kickMsg(token[2]);
		_chList[ch_idx]->delMember(token[2]);
	}
	return ("");
}

void Command::msgSendToClient(string rcv_name, string msg) {
	vector<Client *>::iterator it;

	for (it = _clntList.begin(); it != _clntList.end(); it++) {
		if ((*it)->getNickname() == rcv_name) {
			if (send((*it)->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
		}
	}
}

void Command::msgSendToChannel(string rcv_channel, string msg) {
	vector<Channel *>::iterator it;

	for (it = _chList.begin(); it != _chList.end(); it++) {
		if ((*it)->getChannelName() == rcv_channel) {
			vector<Client *> members = (*it)->getMemberList();
			for (int i = 0; i < (int)members.size(); i++) {
				if (send(members[i]->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
					perr("Error: send error");
			}
		}
	}
}

string Command::privmsg(vector<string> token) {
	if (token[1][0] == '#')
		msgSendToChannel(token[1], token[2]);
	else
		msgSendToClient(token[1], token[2]);
	return ("");
}

string	Command::execute() {
	//여기서 while문을 돌려주면 _cmd[0]이 명령어면 실행하게 해줘야 할듯
	//그리고 JOIN명령어에서 서버의 cout << "O " << msg 가 출력이 안됨 그런데 클라이언트 소켓에는 잘 전달 됨 이거 왜이런지 모르곘음
	//그리고 JOIN명령어 이후에 클라이언트 접속 끊기면 정상종료가 아니라 recv error가 발생함
	vector<string>	token;
	for (vector<string>::iterator iter = _cmd.begin(); iter != _cmd.end(); iter++)
	{
		token = parseExecute(*iter);
		
		if (token[0] == "JOIN") join(token);
		else if (token[0] == "KICK") kick(token);
		else if (token[0] == "MODE") ;
		else if (token[0] == "PASS") ;
		else if (token[0] == "PING") ping(token);
		else if (token[0] == "NICK") nick(token);
		else if (token[0] == "USER") user(token);
		else if (token[0] == "PRIVMSG") privmsg(token);
	}
	return ("");
}

vector<string> Command::getCmd() {
	return _cmd;
}