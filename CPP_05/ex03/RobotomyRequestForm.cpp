#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& oth) : AForm(oth), target(oth.target)
{
	std::cout << "RobotomyRequestForm copy constructor called!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &oth)
{
	if (this != &oth)
		target = oth.target;
	std::cout << "RobotomyRequestForm copy assignment called!" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called!" << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return target;
}

void RobotomyRequestForm::executeFormAction(void) const
{
	srand(time(0)); // Seeds the random number generator (provides it with an initial value), normally using the current time.
	int nbr = rand(); // Returns a random integer.
	if (nbr % 2) // If an even number
		std::cout << "*loud drilling noises*... " << target << " has been robotomized successfully!" << std::endl;
	else // If an odd number
		std::cout << "*VERY loud and disturbing drilling noises*... Robotomy for " << target << " has failed." << std::endl;
}
