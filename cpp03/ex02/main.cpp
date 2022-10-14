#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	{
		ClapTrap ct("claptrap");

		ct.attack("aaaaa");
		ct.takeDamage(6);
		ct.beRepaired(4);
		ct.takeDamage(3);
		ct.beRepaired(5);
		ct.takeDamage(42);
	}
	std::cout << std::endl;
	{
		ScavTrap st("scavtrap");

		st.attack("kimchi");
		st.takeDamage(6);
		st.beRepaired(4);
		st.takeDamage(3);
		st.beRepaired(5);
		st.takeDamage(42);
	}
	std::cout << std::endl;
	{
		FragTrap ft("fragtrap");

		ft.attack("kimchi");
		ft.takeDamage(6);
		ft.beRepaired(4);
		ft.takeDamage(3);
		ft.beRepaired(5);
		ft.takeDamage(42);
	}
	
	


}