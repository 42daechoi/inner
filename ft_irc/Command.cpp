#include "Command.hpp"

Command::Command(string data, Client &client, vector<Client> &clntList, vector<Channel> &chList) : _chList(chList), _clntList(clntList), _client(client), _server("irc.local") {
	char *ptr = strtok((char *)data.c_str(), " \t\n");
	while (ptr != NULL)
	{
		_cmd.push_back(string(ptr));
		ptr = strtok(NULL, " \t\n");
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
				+ _client.getNickname() \
				+ " :Welcome to the Localnet IRC Network " \
				+ _client.getNickname() \
				+ "!" \
				+ _client.getUsername() \
				+ "127.0.0.1\n";
	return (msg);
}

string	Command::makeChangeNickMsg(string cmd)
{
	string msg = ":" \
				+ _client.getNickname() \
				+ "!" \
				+ _client.getUsername() \
				+ "@127.0.0.1 " \
				+ "NICK :";
	if (isSameNick(cmd))
		cmd = cmd + "_";
	msg += cmd + "\n";
	_client.setNickname(cmd);
	return (msg);
}

int		Command::isSameNick(string cmd)
{
	vector<Client>::iterator it;
	for (it = _clntList.begin(); it != _clntList.end(); it++)
		if (it->getNickname() == cmd)
			return (1);
	return (0);
}

void	Command::nick(string opt)
{
	string msg;
	if (_client.getInit() == false)//최초 생성시
	{
		if (isSameNick(opt))
			opt = opt + "_";
		_client.setNickname(opt);
		if (_client.getUsername() != "")//NICK, USER완성시
		{
			msg = makeWelcomeMsg();
			if (send(_client.getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
			else
				_client.setInit(true);
			cout << "O " << msg;
		}
	}
	else//이미 생성 이력 있고 NICK바꿀시
	{
		if (opt != _client.getNickname())//원래 닉네임이랑 같으면 아무 동작 안함
		{
			msg = makeChangeNickMsg(opt); //이 함수 내부에서 set이랑 중복검사함
			if (send(_client.getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
			cout << "O " << msg;
		}
	}
}

void Command::user(string opt)
{
	string msg;

	_client.setUsername(opt);
	if (_client.getNickname() != "" && _client.getInit() == false)
	{
		msg = makeWelcomeMsg();
		if (send(_client.getClntfd(), msg.c_str(), msg.length(), 0) == -1)
			perr("Error: send error");
		else
			_client.setInit(true);
		cout << "O " << msg << endl;
	}
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
		if (ch_name == _chList[i].getChannelName())
			return &_chList[i];
	}
	return NULL;
}

void Command::shoutOutToChannel(Channel *channel) {
	string 			msg;
	vector<Client>	members = channel->getMemberList();

	for (int i = 0; i < (int)members.size(); i++) {
			msg = ":" + _client.getNickname() +  
				+ "!" + members[i].getUsername() +
				+ "@" + "127.0.0.1" + " JOIN :"
				+ channel->getChannelName() + "\n";
			if (send(members[i].getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
			cout << "O " << msg;
	}

	msg = ":irc.local 353 " + _client.getNickname()
		+ channel->getChannelName() + " :@";
	for (int i = 0; i < (int)members.size() - 1; i++)
		msg += members[i].getNickname() + " ";
	msg += members[members.size() - 1].getNickname() + "\n";
	if (send(_client.getClntfd(), msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	cout << "O " << msg;
	msg = ":irc.local 366 " + _client.getNickname()
		+ " " + channel->getChannelName()
		+ " :End of /NAMES list.\n";
	if (send(_client.getClntfd(), msg.c_str(), msg.length(), 0) == -1)
		perr("Error: send error");
	cout << "O " << msg;
}

void Command::join(string opt) {
	string 	ch_name;
	Channel *channel;

	if (opt[0] != '#')
		perr("Error: cannot find #ChannelName");
	
	ch_name = opt;
	if (!(channel = findChannel(ch_name))) {
		channel = new Channel(ch_name, _client);
		_chList.push_back(*channel);
	}
	else 
		channel->addMember(_client);
	_client.addChannel(*channel);
	shoutOutToChannel(channel);
	// delete channel; 이거 하면 새 유저 추가할때마다 채널 사라짐 따라서 세그폴트남 안하는게 맞음
}

void Command::execute() {
	//여기서 while문을 돌려주면 _cmd[0]이 명령어면 실행하게 해줘야 할듯
	//그리고 JOIN명령어에서 OUTPUT이 안나감 왜지...??
	//그리고 JOIN명령어 이후에 클라이언트 접속 끊기면 정상종료가 아니라 recv error가 발생함
	for (vector<string>::iterator iter = _cmd.begin(); iter != _cmd.end(); iter++)
	{
		if (*iter == "JOIN") join(*(iter + 1));
		else if (*iter == "KICK") return;
		else if (*iter == "MODE") return;
		else if (*iter == "PASS") return;
		else if (*iter == "PING") return;
		else if (*iter == "NICK") nick(*(iter + 1));
		else if (*iter == "USER") user(*(iter + 1));
		else if (*iter == "PRIVMSG") return;
	}
	
	// if (_cmd[0] == "JOIN") join();
	// else if (_cmd[0] == "KICK") return;
	// else if (_cmd[0] == "MODE") return;
	// else if (_cmd[0] == "PASS") return;
	// else if (_cmd[0] == "PING") return;
	// else if (_cmd[0] == "NICK") nick();
	// else if (_cmd[0] == "USER") user();
	// else if (_cmd[0] == "PRIVMSG") return;
	// else
	// 	cout << "Error: command execute\n";
}

vector<string> Command::getCmd() {
	return _cmd;
}