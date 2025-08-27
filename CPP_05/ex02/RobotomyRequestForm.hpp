#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &oth);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& oth);
		virtual ~RobotomyRequestForm();
	
		std::string	getTarget(void) const;

		virtual void executeFormAction(void) const;
};

#endif