#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{

	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal();

		WrongAnimal &		operator=( WrongAnimal const & rhs );

		virtual void makeSound(void) const;

		std::string getType(void) const;

	protected:
		std::string type;

};

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i );

#endif /* ***************************************************** WRONGANIMAL_H */