#ifndef PARSER_HPP
# define PARSER_HPP

# include "header.hpp"

class Parser {
	public:
		Parser(string data);

		void printCommand();
	private:
		vector<string>	_cmd;
};

#endif