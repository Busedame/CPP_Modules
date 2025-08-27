# include "AForm.hpp"

AForm::AForm() : name("Default AForm"), isSigned(false), reqSign(20), reqExec(5)
{
	std::cout << "AForm constructor with no args called!" << std::endl;
}

AForm::AForm(std::string name, int reqSign, int reqExec) : name(name), isSigned(false), reqSign(reqSign), reqExec(reqExec)
{
	if (reqSign < 0 || reqExec < 0)
		throw AForm::GradeTooHighException();
	else if (reqSign > 150 || reqExec > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructor with args called!" << std::endl;
}

AForm::AForm(const AForm& oth) : name(oth.name), isSigned(oth.isSigned), reqSign(oth.reqSign), reqExec(oth.reqExec)
{
	std::cout << "AForm copy constructor called!" << std::endl;
}

AForm&	AForm::operator=(const AForm& oth)
{
	if (this != &oth)
		isSigned = oth.isSigned;
	std::cout << "AForm copy assignment called!" << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called!" << std::endl;
}

const std::string& AForm::getName(void) const
{
	return name;
}

bool	AForm::getIsSigned(void) const
{
	return isSigned;
}

void	AForm::setIsSigned(void)
{
	isSigned = true;
}

int AForm::getReqSign(void) const
{
	return reqSign;
}

int AForm::getReqExec(void) const
{
	return reqExec;
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > reqSign)
		throw AForm::GradeTooLowException();
	else
		isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned)
		throw AForm::FormNotSigned();
	else if (executor.getGrade() > reqExec)
		throw AForm::GradeTooLowException();
	this->executeFormAction();
}

const char* AForm::GradeTooHighException::what() const throw() 
{
	return "grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw() 
{
	return "grade is too low.";
}

const char* AForm::FormNotSigned::what() const throw()
{
	return "form is not signed.";
}

std::ostream&	operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << std::endl;
	os << "Minimum requirement for signature: " << f.getReqSign() << std::endl;
	os << "Minimum requirement for execution: " << f.getReqExec() << std::endl;

	if (f.getIsSigned())
		os << "AForm is signed.";
	else
		os << "AForm is not signed.";

	return os;
}
