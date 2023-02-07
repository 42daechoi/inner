#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};


		Form();
		Form(std::string name, int gradeToSign, int gradeToExe);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		int  gradeFlag(void);
		void beSigned(Bureaucrat b);

		const std::string getName(void) const;
		bool getSignFlag(void) const;
		int getGradeToS(void) const;
		int getGradeToE(void) const;

	private:
		const std::string name;
		bool  signFlag;
		const int gradeToSign;
		const int gradeToExe;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */