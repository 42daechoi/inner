#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	std::cout << "WrongCat - default constructor called\n";
	type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat & src )
{
	std::cout << "WrongCat - copy constructor called\n";
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "WrongCat - destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongCat const & i )
{
	o << "WrongAnimal type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meow~~\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */