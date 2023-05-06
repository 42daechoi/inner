#include "header.hpp"

void perr(string str) {
	cout << str << endl;
	cout << "errno : " << errno << endl;
	exit(1);
}