#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "header.hpp"
# include "Client.hpp"

class Client;

class Channel {
	public:
		Channel(string ch_name, Client op_clnt);

		void	addMember(Client clnt);
		// void	quitChannel();

		string		 	getChannelName();
		void 			setChannelName(string ch_name);
		vector<Client> 	getMemberList();
	private:
		string 			_ch_name;
		vector<Client>	_member;
};

#endif