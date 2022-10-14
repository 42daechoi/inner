#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	this->name = "";
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "Defualt FragTrap is called\n";
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << name << " of FragTrap is created\n";
}

FragTrap::FragTrap( const FragTrap & src )
{
	std::cout << "Copy constructor called(FragTrap)\n";
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << name << " is destroyed(FragTrap)\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << name << "Assignment operator called(FragTrap)\n";
	if ( this != &rhs )
		this->name = rhs.getName();
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys(void)
{
	std::cout << "High five, Let's go\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */