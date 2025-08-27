#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	try
	{
		Bureaucrat x("Bob", 60);
		ShrubberyCreationForm a("Dog");
		PresidentialPardonForm b("Cow");
		RobotomyRequestForm c("Cat");

		x.signForm(a);
		x.signForm(b);
		x.signForm(c);
		x.executeForm(a);
		x.executeForm(b);
		x.executeForm(c);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
