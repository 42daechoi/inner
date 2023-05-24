#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "../header.hpp"

using namespace std;

class Client;

class Channel {
	public:
		Channel(string ch_name, Client *op_clnt, ostream& logfile);

		bool	addMember(Client *clnt, string password);
		void	delMember(string clnt_nickname, bool isrec);
		void	kickMsg(Client *client, string kick_name);
		bool 	inviteChannel(Client *clnt);
		void 	addOperList(string clnt_nickname);
		void 	delInviteList(string clnt_nickname);
		void 	delOperList(string clnt_nickname);
		void 	addOperList(Client *client);
		bool 	isOperator(string clnt_nickname);
		bool 	isMember(string clnt_nickname);
		void 	sendTopic(Client *clnt);
		void 	sendDenyJoin(Client *clnt);
		void 	sendWrongPass(Client *clnt);
		bool 	isInvitee(Client *clnt);
		bool 	isPassMode();

		void 	sendCodeMsg(int fd, string code, string nickname, string target, string msg);

		string		 		getChannelName();
		void 				unsetPassword();
		void 				setChannelName(string ch_name);
		void 				setInviteOnly(bool flag);
		void 				setTopicFlag(bool flag);
		void 				setPassword(string password);
		void 				setLimitNum(string limit_str);
		bool 				getTopicFlag();
		void 				setTopic(string topic);
		bool 				getInviteOnly();
		vector<Client *>  	getOperList();
		vector<Client *> 	getMemberList();

	private:
		string 				_ch_name;
		vector<Client *>	_member;
		bool 				_invite_only;
		bool 				_topic_flag;
		string 				_topic;
		string 				_password;
		int 				_limit_number;
		vector<Client *>	_inviteList;
		vector<Client *>	_operList;
		ostream&			_logfile;
};

#endif