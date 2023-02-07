#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : Form("rrf", 72, 45), target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("rrf", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : Form(src), target(src.target)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->signFlag = rhs.getSignFlag();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
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

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignFlag())
		throw ExecuteFailedException();
	else if (executor.getGrade() > this->gradeToExe)
		throw GradeTooLowException();
	else {
		std::cout << "driiiiiiiiiiiiiiilllll\n";
		std::srand(time(NULL));
		if (rand() % 2)
			std::cout << "Robotomized successfully!\n";
		else
			std::cout << "Robotomized failed...\n";
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */