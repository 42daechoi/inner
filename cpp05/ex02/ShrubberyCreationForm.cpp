#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form("scf", 145, 137), target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("scf", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : Form(src), target(src.target)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->signFlag = rhs.getSignFlag();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignFlag())
		throw ExecuteFailedException();
	else if (executor.getGrade() > this->gradeToExe)
		throw GradeTooLowException();
	else {
		std::ofstream ofs;
		ofs.open(target + "_shrubbery");
		ofs << "    *    " << std::endl;
		ofs << "   ***   " << std::endl;
		ofs << "  *****  " << std::endl;
		ofs << " ******* " << std::endl;
		ofs << "   | |   " << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */