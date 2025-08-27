#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &oth);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& oth);
		virtual ~ShrubberyCreationForm();

		std::string	getTarget(void) const;

		virtual void executeFormAction(void) const;
};

#endif