#ifndef COMMAND_HPP
# define COMMAND_HPP

# include "header.hpp"
# include "Client.hpp"
# include "Channel.hpp"

# define SERVERNEMA irc.local

class Command {
	public:
		Command(string data, Client &client, vector<Client> &clntList, vector<Channel> &chList);

		void		printCommand();
		string		makeWelcomeMsg();
		string		makeChangeNickMsg(string cmd);
		int			isSameNick(string cmd);
		void		user(string opt);
		void		nick(string opt);
		void		execute();

		void 		sendToClnt();
		void 		shoutOutToChannel(Channel *channel);
		Channel* 	findChannel(string ch_name);
		int 		findSharp();
		void		join(string opt);

		vector<string> getCmd();
	private:
		vector<Channel>&	_chList;
		vector<Client>&		_clntList;
		Client& 			_client;
		vector<string>		_cmd;
		const string		_server;
};

#endif