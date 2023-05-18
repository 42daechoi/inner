#ifndef COMMAND_HPP
# define COMMAND_HPP

# include "header.hpp"
# include "Client.hpp"
# include "Channel.hpp"

# define SERVERNEMA irc.local

class Command {
	public:
		Command(string data, Client *client, vector<Client *> &clntList, vector<Channel *> &chList, string cpass);

		void			printCommand();
		string			makeWelcomeMsg();
		string			makeChangeNickMsg(string cmd);
		int				isSameNick(string cmd);
		string			user(vector<string> token);
		string			nick(vector<string> token);
		// vector<string>	parseExecute(string com);
		vector<string>	parseExecute(const string& com);
		int 			execute();


		string			join(vector<string> token);
		void 			sendToClnt();
		string 			shoutOutToChannel(Channel *channel);
		Channel 		*findChannel(string ch_name);
		int 			findSharp();

		void			kick(vector<string> token);
		int 			findChannelIdx(string ch_name);
		void 			youAreNotOp(string ch_name);
		
		string			privmsg(vector<string> token);
		void 			msgSendToClient(string rcv_name, string msg);
		void 			msgSendToChannel(string rcv_channel, string msg);

		int 			pass(vector<string> token);

		void 			part(vector<string> token);

		string			ping(vector<string> token);
		vector<string>	getCmd();
	private:
		vector<Channel *>&	_chList;
		vector<Client *>&	_clntList;
		Client* 			_client;
		vector<string>		_cmd;
		const string		_server;
		string 				_cpass;
};

#endif