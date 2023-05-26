#ifndef HEADER_HPP
# define HEADER_HPP

# include <sys/socket.h>
# include <arpa/inet.h>
# include <cstdlib>
# include <iostream>
# include <cstring>
# include <string>
# include <cctype>
# include <unistd.h>
# include <sys/poll.h>
# include <vector>
# include <algorithm>
# include <iterator>
# include <map>
# include <fcntl.h>
# include <limits.h>
# include <cerrno>
# include <climits>
# include <fstream>
# include <cctype>
# include <sstream>
# include "Client/Client.hpp"
# include "Channel/Channel.hpp"

# define MAX_SOCKET FOPEN_MAX

using namespace std;

int		check_port(char **av);
void	perr(string str);
void 	noMemberChannel(vector<Channel *> &chList);
void	delChannelList(vector<Channel *> &chList, string clnt_nickname);
void 	printInput( ostream& logFile, string msg);
void 	printOutput( ostream& logFile, string msg);
void 	incorrectPassword(int clntfd, vector<struct pollfd> &vfds, vector<Client *> &clntList, int i);
void 	quitClient(int clntfd,  vector<struct pollfd> &vfds, vector<Client *> &clntList, int i, vector<Channel *> &chList);
pollfd 	makePollfd(int fd);
#endif