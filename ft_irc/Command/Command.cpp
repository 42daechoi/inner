#include "Command.hpp"

Command::Command(string data, Client *client, vector<Client *> &clntList, vector<Channel *> &chList, string cpass, ostream& logfile) : _chList(chList), _clntList(clntList), _client(client), _server("irc.local"), _cpass(cpass), _logfile(logfile) {
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


vector<string> Command::parseExecute(const string& com) {
    vector<string> token;
    std::istringstream iss(com);
    string tokenStr;
    while (iss >> tokenStr) {
        // 토큰의 앞뒤에 있는 공백 문자 제거
        tokenStr.erase(0, tokenStr.find_first_not_of(" \t\n"));
        tokenStr.erase(tokenStr.find_last_not_of(" \t\n") + 1);

        token.push_back(tokenStr);
    }
    return token;
}



int	Command::execute() {
	//여기서 while문을 돌려주면 _cmd[0]이 명령어면 실행하게 해줘야 할듯
	//그리고 JOIN명령어에서 서버의 cout << "O " << msg 가 출력이 안됨 그런데 클라이언트 소켓에는 잘 전달 됨 이거 왜이런지 모르곘음
	//그리고 JOIN명령어 이후에 클라이언트 접속 끊기면 정상종료가 아니라 recv error가 발생함
	vector<string>	token;
	string	msg;

	for (vector<string>::iterator iter = _cmd.begin(); iter != _cmd.end(); iter++)
	{
		token = parseExecute(*iter);
		
		if (token[0] == "JOIN") join(token);
		else if (token[0] == "KICK") kick(token);
		else if (token[0] == "PART") part(token);
		else if (token[0] == "PASS") {
			if (pass(token) == -1) return -1;
		}
		else if (token[0] == "PING") ping(token);
		else if (token[0] == "NICK") nick(token);
		else if (token[0] == "USER") user(token);
		else if (token[0] == "PRIVMSG") privmsg(token);
		else if (token[0] == "WHO") who(token);
		else if (token[0] == "INVITE") invite(token);
		else if (token[0] == "MODE") mode(token);
	}
	if (_client->getNickname() != "" && _client->getUsername() != "" && _client->getPassword() == "") {
		msg = "please type password\n";
		if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1) {
			perr("Error: send error");
		_logfile << "O " << msg;
		}
		return -1;
	}
	return 0;
}

vector<string> Command::getCmd() {
	return _cmd;
}