#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap st("scavtrap");
	ClapTrap ct("claptrap");

	st.attack("kimchi");

	ct.takeDamage(6);
	ct.beRepaired(4);
	ct.takeDamage(3);
	ct.beRepaired(8);
	ct.takeDamage(42);
	std::cout << std::endl;

	st.takeDamage(6);
	st.beRepaired(4);
	st.takeDamage(3);
	st.beRepaired(8);
	st.takeDamage(42);
}