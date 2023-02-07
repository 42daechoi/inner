#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class AMateria;

class Character : public ICharacter
{

	public:

		Character();
		Character(std::string name);
		Character( Character const & src );
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		Character &		operator=( Character const & rhs );

	private:
		std::string name;
		AMateria 	*inventory[4];
};

#endif /* ******************************************************* CHARACTER_H */