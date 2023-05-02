#include "Command.hpp"

Command::Command(string data, Client &client, vector<Client> clntList) : _clntList(clntList), _client(client), _server("irc.local") {
	char *ptr = strtok((char *)data.c_str(), " \t");
	while (ptr != NULL)
	{
		_cmd.push_back(string(ptr));
		ptr = strtok(NULL, " \t");
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

string	Command::makeChangeNickMsg()
{
	string msg = ":" \
				+ _client.getNickname() \
				+ "!" \
				+ _client.getUsername() \
				+ "@127.0.0.1 " \
				+ "NICK :";
	if (isSameNick())
		_cmd[1] = _cmd[1] + "_";
	msg += _cmd[1] + "\n";
	_client.setNickname(_cmd[1]);
	return (msg);
}

int		Command::isSameNick()
{
	vector<Client>::iterator it;
	for (it = _clntList.begin(); it != _clntList.end(); it++)
		if (it->getNickname() == _cmd[1])
			return (1);
	return (0);
}

void	Command::nick()
{
	string msg;

	if (_client.getInit() == false)//최초 생성시
	{
		if (isSameNick())
			_cmd[1] = _cmd[1] + "_";
		_client.setNickname(_cmd[1]);
		if (_client.getUsername() != "")//NICK, USER완성시
		{
			msg = makeWelcomeMsg();
			if (send(_client.getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
			else
				_client.setInit(true);
		}
	}
	else//이미 생성 이력 있고 NICK바꿀시
	{
		if (_cmd[1] != _client.getNickname())//원래 닉네임이랑 같으면 아무 동작 안함
		{
			msg = makeChangeNickMsg(); //이 함수 내부에서 set이랑 중복검사함
			if (send(_client.getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
		}
	}
}

void Command::user()
{
	string msg;

	_client.setUsername(_cmd[1]);
	if (_client.getNickname() != "" && _client.getInit() == false)
	{
		msg = makeWelcomeMsg();
		if (send(_client.getClntfd(), msg.c_str(), msg.length(), 0) == -1)
			perr("Error: send error");
		else
			_client.setInit(true);
	}
}

void Command::execute() {
	if (_cmd[0] == "JOIN")	return;
	else if (_cmd[0] == "KICK") return;
	else if (_cmd[0] == "MODE") return;
	else if (_cmd[0] == "PASS") return;
	else if (_cmd[0] == "PING") return;
	else if (_cmd[0] == "QUIT") return;
	else if (_cmd[0] == "NICK")
		nick();
	else if (_cmd[0] == "USER")
		user();
	else if (_cmd[0] == "PRIVMSG") return ;
	// else
	// 	cout << "Error: command execute\n";
}

vector<string> Command::getCmd() {
	return _cmd;
}