#ifndef COMMAND_HPP
# define COMMAND_HPP

# include "header.hpp"
# include "Client.hpp"
# include "Channel.hpp"

# define SERVERNEMA irc.local

class Command {
	public:
		Command(string data, Client &client, vector<Client> &clntList, vector<Channel> &chList);

		void			printCommand();
		string			makeWelcomeMsg();
		string			makeChangeNickMsg(string cmd);
		int				isSameNick(string cmd);
		string			user(vector<string> token);
		string			nick(vector<string> token);
		vector<string>	parseExecute(string com);
		string			execute();

		void 			sendToClnt();
		string 			shoutOutToChannel(Channel *channel);
		Channel* 		findChannel(string ch_name);
		int 			findSharp();
		string			join(vector<string> token);
		string			ping(vector<string> token);
		vector<string>	getCmd();
	private:
		vector<Channel>&	_chList;
		vector<Client>&		_clntList;
		Client& 			_client;
		vector<string>		_cmd;
		const string		_server;
};

#endif