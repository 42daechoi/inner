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
		void			user(vector<string> token);
		void			nick(vector<string> token);
		vector<string>	parseExecute(string com);
		void			execute();

		void 			sendToClnt();
		void 			shoutOutToChannel(Channel *channel);
		Channel* 		findChannel(string ch_name);
		int 			findSharp();
		void			join(vector<string> token);
		void 			ping(vector<string> token);
		vector<string>	getCmd();
	private:
		vector<Channel>&	_chList;
		vector<Client>&		_clntList;
		Client& 			_client;
		vector<string>		_cmd;
		const string		_server;
};

#endif