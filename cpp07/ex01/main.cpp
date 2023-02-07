#include <string>
#include <iostream>
#include "iter.hpp"


int main()
{
	std::string arr1[3] = {"hello", "world", "daechoi"};
	int 		arr2[3] = {10, 20 ,30};

	iter(arr1, 3, print);
	iter(arr2, 3, print);
	return (0);
}