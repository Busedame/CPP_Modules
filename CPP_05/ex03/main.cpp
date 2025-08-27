#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern Carl;
	AForm	*form;

	form = Carl.makeForm("shrubbery creation", "Kaja");
	if (!form)
		return (1);
	try
	{
		Bureaucrat Bob("Bob", 0);
		
		(*form).beSigned(Bob);
		Bob.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete form;
}
