#include "CrappyPhonebook.hpp"

int	main(void)
{
	std::string Input;
	PhoneBook PB;

	InitProgram();
	while (1)
	{
		std::cout << "\033[0;33mType your command here: \033[0m"; std::getline(std::cin, Input);
		if ("ADD" == ConvertInputToUppercase(Input))
			PB.AddContactToPhoneBook();
		else if ("SEARCH" == ConvertInputToUppercase(Input))
			PB.DisplayContacts();
		else if ("EXIT" == ConvertInputToUppercase(Input))
			ExitProgram();
		else
			std::cout << "\033[0;31mInvalid command. Use 'ADD', 'SEARCH' or 'EXIT'.\033[0m" << std::endl;
	}
}
