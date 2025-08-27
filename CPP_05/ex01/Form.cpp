# include "Form.hpp"

Form::Form() : name("Default form"), isSigned(false), reqSign(20), reqExec(5)
{
	std::cout << "Form constructor with no args called!" << std::endl;
}

Form::Form(std::string name, int reqSign, int reqExec) : name(name), isSigned(false), reqSign(reqSign), reqExec(reqExec)
{
	if (reqSign < 0 || reqExec < 0)
		throw Form::GradeTooHighException();
	else if (reqSign > 150 || reqExec > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor with args called!" << std::endl;
}

Form::Form(const Form& oth) : name(oth.name), isSigned(oth.isSigned), reqSign(oth.reqSign), reqExec(oth.reqExec)
{
	std::cout << "Form copy constructor called!" << std::endl;
}

Form&	Form::operator=(const Form& oth)
{
	if (this != &oth)
		isSigned = oth.isSigned;
	std::cout << "Form copy assignment called!" << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called!" << std::endl;
}

const std::string& Form::getName(void) const
{
	return name;
}

bool	Form::getIsSigned(void) const
{
	return isSigned;
}

void	Form::setIsSigned(void)
{
	isSigned = true;
}

int Form::getReqSign(void) const
{
	return reqSign;
}

int Form::getReqExec(void) const
{
	return reqExec;
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > reqSign)
		throw Form::GradeTooLowException();
	else
		isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() 
{
	return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw() 
{
	return "Grade is too low.";
}

std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << std::endl;
	os << "Minimum requirement for signature: " << f.getReqSign() << std::endl;
	os << "Minimum requirement for execution: " << f.getReqExec() << std::endl;

	if (f.getIsSigned())
		os << "Form is signed.";
	else
		os << "Form is not signed.";

	return os;
}
