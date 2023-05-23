#include "Command.hpp"

int Command::pass(vector<string> token) {
	if (_cpass != token[1]) {
		string msg = "wrong password\n";
		if (send(_client->getClntfd(), msg.c_str(), msg.length(), 0) == -1)
			perr("Error: send error");
		printLog(msg);
		return -1;
	}
	_client->setPassword(token[1]);
	return 0;
}
