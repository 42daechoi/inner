#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_decimal = 0;
}

Fixed::Fixed( const Fixed & src )
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

Fixed &Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		this->fixed_decimal = rhs.getRawBits();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
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