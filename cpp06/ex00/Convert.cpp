#include "Convert.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Convert::Convert()
{
}

Convert::Convert(std::string prevString) : prevString(prevString)
{
	try {
		if (isChar(prevString))
			dValue = static_cast<double>(prevString[0]);
		else
			dValue = std::strtod(prevString.c_str(), NULL);
	} catch(const std::exception& e) {
		std::cerr << "Argument error" << std::endl;
	}
}

Convert::Convert( const Convert & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Convert::~Convert()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Convert &				Convert::operator=( Convert const & rhs )
{
	if ( this != &rhs )
	{
		this->prevString = rhs.prevString;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool Convert::isChar(std::string prevString)
{
	if (prevString.length() == 1 && !std::isdigit(prevString[0]))
		return (true);
	return (false);
}

void Convert::toChar(void)
{
	std::cout << "char: ";
	if (isinf(dValue) || isnan(dValue))
		std::cout << "impossible";
	else if (!isprint(dValue))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(dValue) << "'";
	std::cout << std::endl;
}

void Convert::toInt(void)
{
	std::cout << "int: ";
	if (isinf(dValue) || isnan(dValue))
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(dValue);
	std::cout << std::endl;
}

void Convert::toFloat(void)
{
	std::cout << "float: ";
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << static_cast<float>(dValue) << "f";
	std::cout << std::endl;
}

void Convert::toDouble(void)
{
	std::cout << "double: ";
	std::cout << dValue;
	std::cout << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */