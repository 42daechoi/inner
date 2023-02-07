#include "Convert.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Argument error\n";
		exit(1);
	}
	Convert convert(av[1]);

	convert.toChar();
	convert.toInt();
	convert.toFloat();
	convert.toDouble();
	return 0;
}