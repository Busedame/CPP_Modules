#include "Bureaucrat.hpp"

int	main()
{
	std::cout << ">>>>>>TESTING INSERTION OVERLOAD<<<<<<" << std::endl;
	try
	{
		Bureaucrat a;
		std::cout << a << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << ">>>>>>TESTING INVALID INCREMENT<<<<<<" << std::endl;
	try
	{
		Bureaucrat a("Rolf", 0);
		std::cout << a << std::endl;
		a.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << ">>>>>>TESTING INVALID CONSTRUCTION ARGUMENT<<<<<<" << std::endl;
	try
	{
		Bureaucrat a("Max", -1);
		std::cout << a << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << ">>>>>>TESTING GETTERS<<<<<<" << std::endl;
	try
	{
		Bureaucrat a("Testings Testingsson", 0);
		std::cout << a << std::endl;
		std::cout << a.getGrade() << std::endl;
		std::cout << a.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << ">>>>>>TESTING COPY CONSTRUCTOR<<<<<<" << std::endl;
	try
	{
		Bureaucrat a("Original", 0);
		std::cout << "ORIGINAL: " << a << std::endl;
		Bureaucrat b(a);
		std::cout << "COPY: " << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << ">>>>>>TESTING CHAINED COPY ASSIGNMENT<<<<<<" << std::endl;
	try
	{
		Bureaucrat a("A", 0);
		std::cout << "A: " << a << std::endl;
		Bureaucrat b("B", 130);
		std::cout << "B before assignment: " << b << std::endl;
		Bureaucrat c("C", 42);
		std::cout << "C before assignment: " << c << std::endl;
		c = b = a;
		std::cout << "B after assignment: " << b << std::endl;
		std::cout << "C after assignment: " << c << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

}
