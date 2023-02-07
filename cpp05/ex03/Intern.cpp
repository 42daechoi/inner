#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Form *Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *ret = NULL;
	int i;

	for (i = 0; i < 3; i++) {
		if (name == names[i]) {
			break ;	
		}
	}
	switch (i)
	{
		case 0:
			ret = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << name << std::endl;
			break;
		case 1:
			ret = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << name << std::endl;
			break;
		case 2:
			ret = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << name << std::endl;
			break;
		default:
			std::cout << name << " is doesn't exist. Check the form name.\n";
			break;
	}
	return (ret);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */