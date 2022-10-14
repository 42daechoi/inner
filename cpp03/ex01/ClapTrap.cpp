#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	name = "";
	hit = 10;
	energy = 10;
	damage = 0;
	std::cout << name << "Default ClapTrap is created\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hit(10), energy(10), damage(0)
{
	std::cout << name << " of ClapTrap is created\n";
}

ClapTrap::ClapTrap( const ClapTrap &src )
{
	std::cout << "Copy constructor called(ClapTrap)\n";
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << name << " is destroyed(ClapTrap)\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &ClapTrap::operator=( ClapTrap const &rhs )
{
	if ( this != &rhs )
		this->name = rhs.getName();
	std::cout << "ClapTrap assignment operator called\n";
	return *this;
}

std::ostream &operator<<( std::ostream &o, ClapTrap const &i )
{
	o << "Name is" << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack(const std::string& target)
{
	if (energy == 0) {
		std::cout << "Not enough energy to attack.\n";
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!\n";
	energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hit -= amount;
	if (hit <= 0) {
		std::cout << "Take huge " << amount << " damage, ";
		std::cout << name << " is dead\n";
		hit = 0;
	}
	else
		std::cout << name << " takes " << amount << " damage, " << hit << " hit point left.\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy == 0) {
		std::cout << "Not enough energy to repair.\n";
		return ;
	}
	std::cout << "Repair " << amount << " hit point, " << hit << " hit point left.(energy point : " << energy << ")\n";
	energy--;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ClapTrap::getName(void) const
{
	return (name);
}

/* ************************************************************************** */