#ifndef COMMAND_HPP
# define COMMAND_HPP

# include "header.hpp"
# include "Client.hpp"

# define SERVERNEMA irc.local

class Command {
	public:
		Command(string data, Client &client);

		void	printCommand();
		string	makeWelcomeMsg();
		void	user();
		void	nick();
		void	execute();

		vector<string> getCmd();
	private:
		Client& 		_client;
		vector<string>	_cmd;
		const string	_server;
};

#endif