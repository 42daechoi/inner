#include "Parser.hpp"

Parser::Parser(string data) {
	char *ptr = strtok((char *)data.c_str(), " \t");
	while (ptr != NULL)
	{
		_cmd.push_back(string(ptr));
		ptr = strtok(NULL, " \t");
	}
}

void Parser::printCommand() {
	for (vector<string>::iterator it = _cmd.begin(); it != _cmd.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n";
}