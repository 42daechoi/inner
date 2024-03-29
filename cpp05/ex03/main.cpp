#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ostream>

int main() {
	std::cout << "-----Test#0 Intern::makeForm(): Success-----" << std::endl;
	{
		Intern intern;
		Form *scf;
		Form *rrf;
		Form *ppf;

		scf = intern.makeForm("shrubbery creation", "a");
		rrf = intern.makeForm("robotomy request", "b");
		ppf = intern.makeForm("presidential pardon", "c");

		std::cout << *scf << std::endl;
		std::cout << *rrf << std::endl;
		std::cout << *ppf << std::endl;

		delete scf;
		delete rrf;
		delete ppf;
	}
	std::cout << std::endl;

	std::cout << "-----Test#1 Intern::makeForm(): Failure-----" << std::endl;
	{
		Intern intern;
		Form *nonExistentForm;

		nonExistentForm = intern.makeForm("nonExistentForm", "name");
	}
	std::cout << std::endl;

	return 0;
}