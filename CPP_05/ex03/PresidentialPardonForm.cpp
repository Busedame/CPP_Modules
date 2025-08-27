#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& oth) : AForm(oth), target(oth.target)
{
	std::cout << "PresidentialPardonForm copy constructor called!" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &oth)
{
	if (this != &oth)
		target = oth.target;
	std::cout << "PresidentialPardonForm copy assignment called!" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called!" << std::endl;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return target;
}

void PresidentialPardonForm::executeFormAction(void) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
