#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default bureaucrat"), grade(150)
{
	std::cout << "Bureaucrat constructor with no args called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 0)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat constructor with args called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& oth) : name(oth.name), grade(oth.grade)
{
	std::cout << "Bureaucrat copy constructor called!" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& oth)
{
	if (this != &oth)
		grade = oth.grade;
	std::cout << "Bureaucrat copy assignment called!" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called!" << std::endl;
}

int	Bureaucrat::getGrade(void) const
{
	return grade;
}

const std::string&	Bureaucrat::getName(void) const
{
	return name;
}

void	Bureaucrat::incrementGrade(void)
{
	if (grade == 0)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

void	Bureaucrat::signForm(Form &f)
{
	if (f.getIsSigned())
		std::cout << name << " couldn't sign '" << f.getName() << "' because it has already been signed." << std::endl;
	else if (grade > f.getReqSign())
		std::cout << name << " couldn't sign '" << f.getName() << "' because bureaucrat's grade is too low." << std::endl;
	else
	{
		f.beSigned(*this);
		std::cout << name << " signed '" << f.getName() << "'." << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return "Grade is too low.";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	return os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}