#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool	isSigned;
		const int	reqSign;
		const int	reqExec;

	public:
		// Constructors and destructor
		AForm();
		AForm(std::string name, int reqSign, int reqExec);
		AForm(const AForm& oth);
		AForm&	operator=(const AForm& oth);
		virtual ~AForm();

		// Getters
		const std::string& getName(void) const;
		bool	getIsSigned(void) const;
		int getReqSign(void) const;
		int getReqExec(void) const;

		// Setters
		void	setIsSigned(void);

		// Sign AForm
		void	beSigned(Bureaucrat &b);

		// Execute AForm
		void	execute(Bureaucrat const & executor) const;
		virtual void executeFormAction(void) const = 0;

		// Exceptions
		class	GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
	
		class	FormNotSigned : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif