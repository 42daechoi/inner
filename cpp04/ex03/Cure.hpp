#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class AMateria;

class Cure : public AMateria
{

	public:

		Cure();
		Cure( Cure const & src );
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);

		Cure &		operator=( Cure const & rhs );


};

#endif /* ************************************************************ CURE_H */