#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{

	public:

		AMateria();
		AMateria( AMateria const & src );
		virtual ~AMateria();
		AMateria(std::string const & type);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;

		AMateria &		operator=( AMateria const & rhs );

	protected:
		std::string type;
};

#endif /* ******************************************************** AMATERIA_H */