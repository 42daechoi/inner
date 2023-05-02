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

using namespace std;

int		check_port(char **av);
void	perr(string str);

#endif