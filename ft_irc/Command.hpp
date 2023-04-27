#ifndef COMMAND_HPP
# define COMMAND_HPP

# include "header.hpp"
# include "Client.hpp"

class Command {
	public:
		Command(string data, Client &client);

		void printCommand();
		void execute();

		vector<string> getCmd();
	private:
		Client& 		_client;
		vector<string>	_cmd;
};

#endif