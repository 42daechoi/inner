#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap ct("jaeywon");

	ct.attack("kimchi");
	ct.takeDamage(6);
	ct.beRepaired(4);
	ct.takeDamage(3);
	ct.beRepaired(8);
	ct.takeDamage(42);
}