#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN"; // A string with value "HI THIS IS BRAIN".
	std::string *stringPTR = &str; // A pointer to str, it's assigned both the same value and memory address, but needs to be dereferenced to access value.
	std::string& stringREF = str; // A reference to str, works like an alias, as it's assigned both the same value and memory address. Does NOT need to be dereferenced to access value.
	//std::string stringCPY = str; // A copy of str. Will hold the same value, but NOT the same memory address.

	std::cout << &str << std::endl; // Memory address held by str.
	std::cout << stringPTR << std::endl; // Memory address held by stringPTR.
	std::cout << &stringREF << std::endl; // Memory address held by stringREF.

	std::cout << str << std::endl; // Value held by str.
	std::cout << *stringPTR << std::endl; // Value held by stringPTR.
	std::cout << stringREF << std::endl; // Value held by stringREF.
}