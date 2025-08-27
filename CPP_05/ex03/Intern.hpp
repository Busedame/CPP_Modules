#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include <cctype>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

struct FormPair
{
	std::string	name;
	AForm* (*creator)(std::string); // A pointer to a function that takes a std::string and returns an AForm*".
};

class Intern
{
	public:
		Intern();
		Intern(const Intern& oth);
		Intern&	operator=(const Intern& oth);
		~Intern();

		static AForm*	createShrubbery(std::string target); // Static functions do NOT have a this pointer.
		static AForm*	createPresidential(std::string target); // They behave like normal (free) functions inside the class namespace.
		static AForm*	createRobotomy(std::string target); // You can call them without an object:
		AForm*	makeForm(std::string name, std::string target);
};

#endif