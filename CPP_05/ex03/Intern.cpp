#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called!" << std::endl;
}

Intern::Intern(const Intern& oth)
{
	(void)oth;
	std::cout << "Intern copy constructor called!" << std::endl;
}

Intern&	Intern::operator=(const Intern& oth)
{
	(void)oth;
	std::cout << "Intern copy assignment called!" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called!" << std::endl;
}

AForm*	Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	FormPair formPairs[] = {{"shrubbery creation", &Intern::createShrubbery}, {"presidential pardon", &Intern::createPresidential}, {"robotomy request", &Intern::createRobotomy}};

	for (std::size_t i = 0; i < name.length(); i++) // Makes sure everything is lowercase.
		name[i] = std::tolower(name[i]);
	
	for (int i = 0; i < 3; i++) // Iterates through the formPairs.
	{
		if (formPairs[i].name == name) // If it has the same name.
		{
			std::cout << "Intern creates " << name << "." << std::endl; // Prints out appropriate message.
			return (formPairs[i].creator(target)); // Returns a form of the specified type.
		}
	}
	std::cerr << "Intern couldn't create " << name << " because it does not exist." << std::endl; // Error message if form doesn't exist.
	return (NULL);
}
