#include "CrappyPhonebook.hpp"

void	ExitProgram(void)
{
	std::string	Input;

	while (1)
	{
		std::cout << "Are you sure you want to exit? All contacts will be lost. (Y/N): "; std::cin >> Input;
		if ("Y" == ConvertInputToUppercase(Input) || "YES" == ConvertInputToUppercase(Input))
		{ 
			std::cout << "\033[0;36mExiting... All the contacts are now lost.\033[0m" << std::endl;
			exit(0);
		}
		else if ("N" == ConvertInputToUppercase(Input) || "NO" == ConvertInputToUppercase(Input))
		{
			std::cout << "Exit cancelled." << std::endl;
			return ;
		}
		else
			std::cout << "\033[0;31mWrong input. Exit cancelled. Enter Y or N.\033[0m" << std::endl;
	}
}

std::string ConvertInputToUppercase(std::string &Input)
{
	std::string UpperCaseInput = Input;
	for (size_t i = 0; i < UpperCaseInput.length(); i++)
		UpperCaseInput[i] = toupper(UpperCaseInput[i]);
	return UpperCaseInput;
}


void	InitProgram(void)
{
	std::cout << "\033[0;36mWelcome to this crappy phonebook! Please enter one out of three commands:\033[0m" << std::endl;
	std::cout << "➕ 'ADD' to add a new contact." << std::endl;
	std::cout << "🔍 'SEARCH' to display existing contacts." << std::endl;
	std::cout << "❌ 'EXIT' to discard the phonebook, and exit the program." << std::endl;
}
