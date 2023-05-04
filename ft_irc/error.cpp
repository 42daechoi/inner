#include "header.hpp"

void perr(string str) {
	cout << str << "\n";
	cout << "errno : " << errno << endl;
	exit(1);
}