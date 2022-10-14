#include "Fixed.hpp"
#include <cmath>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_decimal = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_decimal = n << bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_decimal = roundf(f * static_cast<float>(1 << bits));
}

Fixed::Fixed( const Fixed &src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &Fixed::operator=( Fixed const &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		this->fixed_decimal = rhs.getRawBits();
	return *this;
}

std::ostream &operator<<( std::ostream &o, Fixed const &i )
{
	o << i.toFloat();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float Fixed::toFloat(void) const
{
	return (fixed_decimal / static_cast<float>(1 << bits));
}

int Fixed::toInt(void) const
{
	return (fixed_decimal >> bits);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_decimal);
}

void Fixed::setRawBits(int const raw)
{
	fixed_decimal = raw;
}

/* ************************************************************************** */