#include "Form.hpp"

int	main()
{
	try
	{
		std::cout << ">>>>>>CONSTRUCTING<<<<<<" << std::endl;
		Bureaucrat a("Bob", 20); // Declaring a bureaucrat.
		Bureaucrat b("John", 30); // Declaring another bureaucrat.
		Form	f("Sell your kidneys", 150, 150); // Declaring a form.
		Form	f2("Adopt a pet", 150, 150); // Declaring another form.
		std::cout << std::endl;
		std::cout << ">>>>>>INITIAL FORM STATE<<<<<<" << std::endl;
		std::cout << f << std::endl; // Printing out info about form f.
		std::cout << std::endl;
		std::cout << ">>>>>>BOB IS SIGNING THE FIRST FORM<<<<<<" << std::endl;
		a.signForm(f); // Form f is getting signed by bureaucrat a.
		std::cout << std::endl;
		std::cout << ">>>>>>FORM STATE AFTER SIGNING<<<<<<" << std::endl;
		std::cout << f << std::endl; // Printing out info about form f.
		std::cout << std::endl;
		std::cout << ">>>>>>JOHN TRIES TO SIGN FIRST FORM<<<<<<" << std::endl;
		b.signForm(f); // Form f is trying to get signed by bureaucrat b.
		std::cout << std::endl;
		std::cout << ">>>>>>JOHN TRIES TO SIGN SECOND FORM<<<<<<" << std::endl;
		b.signForm(f2); // Form f2 is getting signed by bureaucrat b.
		std::cout << std::endl;
		std::cout << ">>>>>>DESTRUCTING<<<<<<" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << ">>>>>>TESTING COPY CONSTRUCTOR<<<<<<" << std::endl;
	try
	{
		Bureaucrat b("Bob", 20); // Declaring a bureaucrat.
		Form	f("Sell your kidneys", 150, 150); // Declaring a form.
		Form	f2(f);
		std::cout << f2 << std::endl; // Printing out info about form f3.
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
