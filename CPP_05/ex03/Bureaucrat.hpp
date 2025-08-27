#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int	grade;
	public:
		// Constructors and destructor
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& oth);
		Bureaucrat&	operator=(const Bureaucrat& oth);
		~Bureaucrat();

		// Getters
		int getGrade(void) const;
		const std::string& getName(void) const;

		// Increment and decrement
		void	incrementGrade(void);
		void	decrementGrade(void);

		// Sign form
		void	signForm(AForm &f);

		// Execute form
		void executeForm(AForm const & form) const;

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

// Insertion overload
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif