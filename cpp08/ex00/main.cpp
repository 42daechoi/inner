#include "easyfind.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <deque>

int main()
{
	std::cout << std::endl;
	std::cout << "-----Test #1-----" << std::endl;
    {
		std::vector<int> vec(5, 5);
		for (int i = 0; i < 5; i++)
			vec[i] = i;
		std::vector<int>::iterator found = easyfind(vec, 2);
		if (found == vec.end())
			std::cout << "No value in vector" << std::endl;
		else
			std::cout << "Found " << *found << std::endl;
		if (easyfind(vec, 99) == vec.end())
			std::cout << "No value in vector" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-----Test #2-----" << std::endl;
	{
		std::array<char, 5> arr = {'a', 'b', 'c', 'd', 'e'};
		std::array<char, 5>::iterator found = easyfind(arr, 98);
		if (found == arr.end())
			std::cout << "No value in array" << std::endl;
		else
			std::cout << "Found " << *found << std::endl;
		if (easyfind(arr, 0) == arr.end())
			std::cout << "No value in array" << std::endl;			
	}
	std::cout << std::endl;
	std::cout << "-----Test #3-----" << std::endl;
	{
		std::deque<int> deq;
		for (int i = 0; i < 5; i++)
			deq.push_back(i);
		std::deque<int>::iterator found = easyfind(deq, 4);
		if (found == deq.end())
			std::cout << "No value in deque" << std::endl;
		else
			std::cout << "Found " << *found << std::endl;
		if (easyfind(deq, 99) == deq.end())
			std::cout << "No value in deque" << std::endl;			
	}
	std::cout << std::endl;
}