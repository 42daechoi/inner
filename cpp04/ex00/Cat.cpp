#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	std::cout << "Cat - default constructor called\n";
	type = "Cat";
}

Cat::Cat( const Cat & src )
{
	std::cout << "Cat - copy constructor called\n";
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat - destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "Animal type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound(void) const
{
	std::cout << "Meow~~\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */