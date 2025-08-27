#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool	isSigned;
		const int	reqSign;
		const int	reqExec;

	public:
		// Constructors and destructor
		Form();
		Form(std::string name, int reqSign, int reqExec);
		Form(const Form& oth);
		Form&	operator=(const Form& oth);
		~Form();

		// Getters
		const std::string& getName(void) const;
		bool	getIsSigned(void) const;
		int getReqSign(void) const;
		int getReqExec(void) const;

		// Setters
		void	setIsSigned(void);

		// Sign form
		void	beSigned(Bureaucrat &b);

		// Exceptions
		class	GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif