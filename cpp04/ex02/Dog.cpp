#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	brain = new Brain();
	std::cout << "Dog - default constructor called\n";
	type = "Dog";
}

Dog::Dog( const Dog & src )
{
	std::cout << "Dog - copy constructor called\n";
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog - destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
		this->brain = rhs.getBrain();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << "Animal type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound(void) const
{
	std::cout << "Bark!!\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain *Dog::getBrain(void) const
{
	return (brain);
}

/* ************************************************************************** */