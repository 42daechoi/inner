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


		string			join(vector<string> token);
		void 			sendToClnt();
		string 			shoutOutToChannel(Channel channel);
		int 			findChannel(string ch_name);
		int 			findSharp();

		string			kick(vector<string> token);
		
		string			privmsg(vector<string> token);
		void 			msgSendToClient(string rcv_name, string msg);
		void 			msgSendToChannel(string rcv_channel, string msg);


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