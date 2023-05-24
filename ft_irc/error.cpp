#include "header.hpp"

void perr(string str) {
	cout << str << endl;
	cout << "errno : " << errno << endl;
	exit(1);
}

int	check_port(char **av) {
	int i = -1;
	int port = atoi(av[1]);

	while (av[1][++i]) {
		if (!isdigit(av[1][i]))
			perr("Error: port number");
	}
	if (1024 > port || 49151 < port)
		perr("Error: port number is out of range (1024 ~ 49151)");
	return port;
}