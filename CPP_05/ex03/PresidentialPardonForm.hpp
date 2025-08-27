#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &oth);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& oth);
		virtual ~PresidentialPardonForm();

		std::string	getTarget(void) const;

		virtual void executeFormAction(void) const;
};

#endif