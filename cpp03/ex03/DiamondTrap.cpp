#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap()
{
	this->energy = 50;
	std::cout << "Defualt Diamond called\n";
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->energy = 50;
	ClapTrap::name = name.append("_clap_name");
}

DiamondTrap::DiamondTrap( const DiamondTrap &src )
{
	std::cout << "Copy constructor called(Diamond)\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << ClapTrap::name << " is destroyed(DiamondTrap)\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if ( this != &rhs )
		this->name = rhs.getName();
	std::cout << "DiamondTrap assignment operator called\n";
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << name << ", ClapTrap is " << ClapTrap::name << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */