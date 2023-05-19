#include "Command.hpp"

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

void	Command::nick(vector<string> token)
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
			_logfile << "O " << msg;
		}
	}
	else//이미 생성 이력 있고 NICK바꿀시
	{
		if (token[1] != _client->getNickname())//원래 닉네임이랑 같으면 아무 동작 안함
		{
			msg = makeChangeNickMsg(token[1]); //이 함수 내부에서 set이랑 중복검사함
			if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
				perr("Error: send error");
			_logfile << "O " << msg;
		}
	}
}