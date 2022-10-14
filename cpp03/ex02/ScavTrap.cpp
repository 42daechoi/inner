#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap()
{
	this->name = "";
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "Defualt ScavTrap is called\n";
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << name << " of ScavTrap is created\n";
}

ScavTrap::ScavTrap( const ScavTrap &src )
{
	std::cout << "Copy constructor called(ScapTrap)\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << name << " is destroyed(ScavTrap)\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << name << "Assignment operator called(ScavTrap)\n";
	if ( this != &rhs )
		this->name = rhs.getName();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (energy == 0) {
		std::cout << "Not enough energy to attack.\n";
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!\n";
	energy--;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */