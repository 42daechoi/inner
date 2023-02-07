#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : name(""), signFlag(false), gradeToSign(150), gradeToExe(150)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExe) : name(name), signFlag(false), gradeToSign(gradeToSign), gradeToExe(gradeToExe)
{
	int gf;

	gf = gradeFlag();
	if (gf == 2)
		throw GradeTooHighException();
	else if (gf == 1)
		throw GradeTooLowException();
}

Form::Form( const Form & src ) : name(src.name), gradeToSign(src.gradeToSign), gradeToExe(src.gradeToExe)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->signFlag = rhs.signFlag;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Name : " << i.getName() << std::endl 
	  << "Grade to sign : " << i.getGradeToS() << std::endl
	  << "Grade to execute : " << i.getGradeToE() << std::endl;
	return o;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Sign grade or Execute grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Sign grade or Execute grade is too Low! Or grade is too low to sign");
}

const char *Form::ExecuteFailedException::what() const throw()
{
	return ("Execute failed ! Check the grade.");
}

int Form::gradeFlag(void)
{
	if (gradeToSign > 150 || gradeToExe > 150)
		return (2);
	if (gradeToExe < 1 || gradeToSign < 1 )
		return (1);
	return (0);
}

void Form::beSigned(Bureaucrat b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	else
		signFlag = true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string Form::getName(void) const
{
	return (name);
}

bool Form::getSignFlag(void) const
{
	return (signFlag);
}

int Form::getGradeToS(void) const
{
	return (gradeToSign);
}

int Form::getGradeToE(void) const
{
	return (gradeToExe);
}


/* ************************************************************************** */