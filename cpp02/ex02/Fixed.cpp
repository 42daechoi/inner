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

bool Fixed::operator>(Fixed const &rhs)
{
	if (this->fixed_decimal > rhs.fixed_decimal)
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const &rhs)
{
	if (this->fixed_decimal < rhs.fixed_decimal)
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const &rhs)
{
	if (this->fixed_decimal <= rhs.fixed_decimal)
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const &rhs)
{
	if (this->fixed_decimal >= rhs.fixed_decimal)
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed const &rhs)
{
	if (this->fixed_decimal == rhs.fixed_decimal)
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const &rhs)
{
	if (this->fixed_decimal != rhs.fixed_decimal)
		return (true);
	return (false);
}

Fixed Fixed::operator+(Fixed const &rhs)
{
	Fixed newfixed(this->toFloat() + rhs.toFloat());
	return (newfixed);
}

Fixed Fixed::operator-(Fixed const &rhs)
{
	Fixed newfixed(this->toFloat() - rhs.toFloat());
	return (newfixed);
}
Fixed Fixed::operator*(Fixed const &rhs)
{
	Fixed newfixed(this->toFloat() * rhs.toFloat());
	return (newfixed);
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	Fixed newfixed(this->toFloat() / rhs.toFloat());
	return (newfixed);
}

Fixed &Fixed::operator++()
{
	fixed_decimal++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	fixed_decimal++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	fixed_decimal--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	fixed_decimal--;
	return (temp);
}
/*
** --------------------------------- METHODS ----------------------------------
*/

Fixed &Fixed::max( Fixed &a, Fixed &b )
{
	if (a.fixed_decimal < b.fixed_decimal)
		return (b);
	else
		return (a);
}

const Fixed &Fixed::max( Fixed const &a, Fixed const &b )
{
	if (a.fixed_decimal < b.fixed_decimal)
		return (b);
	else
		return (a);
}

Fixed &Fixed::min( Fixed &a, Fixed &b )
{
	if (a.fixed_decimal > b.fixed_decimal)
		return (b);
	else
		return (a);
}

const Fixed &Fixed::min( Fixed const &a, Fixed const &b )
{
	if (a.fixed_decimal > b.fixed_decimal)
		return (b);
	else
		return (a);
}

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