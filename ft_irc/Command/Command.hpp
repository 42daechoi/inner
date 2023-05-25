#ifndef COMMAND_HPP
# define COMMAND_HPP

# include "../header.hpp"

# define SERVERNEMA irc.local

class Command {
	public:
		Command(string data, Client *client, vector<Client *> &clntList, vector<Channel *> &chList, string cpass, ostream &logfile);

		void			printCommand();
		string			makeWelcomeMsg();
		string			makeChangeNickMsg(string cmd);
		int				isSameNick(string cmd);
		void			user(vector<string> token);
		void			nick(vector<string> token);

		vector<string>	parseExecute(const string& com);
		int 			execute();
		void			sendOptionMsg(int fd, string option, string target, string msg);
		void 			sendCodeMsg(int fd, string code, string target, string msg);
		bool 			isOperator(Client *client, Channel *channel);
		Client 			*findClient(string nickname);
		Channel 		*findChannel(string ch_name);
		void			join(vector<string> token);
		void 			sendToClnt();
		void 			shoutOutToChannel(Channel *channel);

		int 			findSharp();

		void			kick(vector<string> token);
		int 			findChannelIdx(string ch_name);
		void 			youAreNotOp(string ch_name);
		void			printLog(string msg);

		void			privmsg(vector<string> token);
		void 			msgSendToClient(vector<string> token);
		void 			msgSendToChannel(vector<string> token);

		int 			pass(vector<string> token);

		void 			part(vector<string> token);

		void 			who(vector<string> token);

		void 			invite(vector<string> token);

		void 			optionO(Channel *channel, char op_flag, string nickname);
		void			optionL(Channel *channel, char op_flag, vector<string> token);
		void 			optionK(Channel *channel, char op_flag, string password);
		void 			optionT(Channel *channel, char op_flag);
		void 			optionI(Channel *channel, char op_flag);
		void 			mode(vector<string> token);
		
		void 			superinvite(vector<string> token);

		void			ping(vector<string> token);

		void 			sendtoChannelTopic(Channel *channel, string msg);
		void 			topic(vector<string> token);

		vector<string>	getCmd();
	private:
		vector<Channel *>&	_chList;
		vector<Client *>&	_clntList;
		Client* 			_client;
		vector<string>		_cmd;
		const string		_server;
		string 				_cpass;
		ostream&			_logfile;
};

#endif