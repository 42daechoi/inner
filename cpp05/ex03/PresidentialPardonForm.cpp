#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : Form("ppf", 25, 5), target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("ppf", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : Form(src), target(src.target)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->signFlag = rhs.getSignFlag();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << "Name : " 
	  << i.getName() << std::endl
	  << "Grade to sign : "
	  << i.getGradeToS() << std::endl
	  << "Grade to execute : "
	  << i.getGradeToE() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignFlag())
		throw ExecuteFailedException();
	else if (executor.getGrade() > this->gradeToExe)
		throw GradeTooLowException();
	else {
		std::cout << target << " has been pardoned by Zafod Beeblebrox." << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */