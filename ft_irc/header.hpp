#ifndef HEADER_HPP
# define HEADER_HPP

# include <sys/socket.h>
# include <arpa/inet.h>
# include <cstdlib>
# include <iostream>
# include <cstring>
# include <cctype>
# include <unistd.h>
# include <poll.h>

using namespace std;

int		check_port(char **av);
void	perr(string str);

#endif