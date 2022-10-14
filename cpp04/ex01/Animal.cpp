#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	std::cout << "Animal - default constructor called\n";
}

Animal::Animal( const Animal & src )
{
	std::cout << "Animal - copy constructor called\n";
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal - destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << "Animal type = " << i.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound(void) const
{
	std::cout << "default type animal can't make sounds!\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType(void) const
{
	return (type);
}

/* ************************************************************************** */