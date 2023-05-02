#ifndef COMMAND_HPP
# define COMMAND_HPP

# include "header.hpp"
# include "Client.hpp"

# define SERVERNEMA irc.local

class Command {
	public:
		Command(string data, Client &client, vector<Client> clntList);

		void	printCommand();
		string	makeWelcomeMsg();
		string	makeChangeNickMsg();
		int		isSameNick();
		void	user();
		void	nick();
		void	execute();

		vector<string> getCmd();
	private:
		vector<Client> _clntList;
		Client& 		_client;
		vector<string>	_cmd;
		const string	_server;
};

#endif