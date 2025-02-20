#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug(void)
{
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	typedef void (Harl::*HarlMemberFunction)(void); // This line defines a type HarlMemberFunction that represents a pointer to a member function of Harl that takes no arguments and returns void.
	HarlMemberFunction functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; // An array of function pointers is declared and assigned.
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"}; // An array of strings containing the different levels.

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level) // Checks if the current string of the array of strings is the same as the passed level-argument.
		{
			(this->*functions[i])(); // A special pointer available within member functions of a class. It points to the object for which the member function is called.
			// "this" is the pointer to the current object. It is necessary for the compiler to not get confused about which object is calling the function.
			// *functions[i] dereferences the function pointer to get the actual member function.
			// () calls the member function on the current object.
			return ;
		}
	}
	std::cout << "Error: The mode [" << level << "] does not exist." << std::endl;
}
