#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	Span span(5);

	span.addNumber(20);
	span.addNumber(14);

	span.randomNumSet();

	std::vector<int> vec = span.getVector();

	std::cout << "vector list : ";
	for (unsigned int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "longest span : " << span.longestSpan() << std::endl;
	std::cout << "shortest span : " << span.shortestSpan() << std::endl;

}