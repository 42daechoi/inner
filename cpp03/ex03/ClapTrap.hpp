#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		std::string getName(void) const;
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);

		ClapTrap &operator=( ClapTrap const & rhs );

	protected:
		std::string name;
		int 		hit;
		int 		energy;
		int 		damage;
};

std::ostream &operator<<( std::ostream &o, ClapTrap const &i );

#endif /* ******************************************************** CLAPTRAP_H */