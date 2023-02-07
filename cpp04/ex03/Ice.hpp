#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class AMateria;

class Ice : public AMateria
{

	public:

		Ice();
		Ice( Ice const & src );
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);

		Ice &		operator=( Ice const & rhs );

	private:

};


#endif /* ************************************************************* ICE_H */