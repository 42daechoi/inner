#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "../header.hpp"
# include "../Client/Client.hpp"

class Client;

class Channel {
	public:
		Channel(string ch_name, Client *op_clnt, ostream& logfile);

		bool	addMember(Client *clnt);
		void	delMember(string clnt_nickname, bool isrec);
		void	kickMsg(string kick_name);
		bool 	inviteChannel(Client *clnt);
		void 	delInviteList(string clnt_nickname);
		void 	delOperList(string clnt_nickname);
		void 	addOperList(Client *client);
		bool 	isOperator(string clnt_nickname);
		bool 	isMember(string clnt_nickname);
		void 	sendTopic(Client *clnt);

		void	sendOptionMsg(int fd, string nickname, string user, string ip, string option, string target, string msg);
		void 	sendCodeMsg(int fd, string code, string nickname, string target, string msg);

		string		 		getChannelName();
		void 				setChannelName(string ch_name);
		void 				setInviteOnly(bool flag);
		void 				setTopicFlag(bool flag);
		bool 				getTopicFlag();
		bool 				getInviteOnly();
		vector<Client *>  	getOperList();
		vector<Client *> 	getMemberList();

	private:
		string 				_ch_name;
		vector<Client *>	_member;
		bool 				_invite_only;
		bool 				_topic_flag;
		string 				_topic;
		vector<Client *>	_inviteList;
		vector<Client *>	_operList;
		ostream&			_logfile;
};

#endif