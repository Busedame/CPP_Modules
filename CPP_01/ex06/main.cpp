#include "Harl.hpp"

int	print_complaint(Harl harl, int i)
{
	switch (i) // Since the switch statement only works with integers/numbers, I
	// now have an int i indicating which mode we should be in. It will then
	// call the member function "complain" to execute the current mode and all
	// modes above, but not below.
	// E.g. If int i == 2, Harl will complain through "WARNING" and "ERROR".
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
	}
	return (0);
}

int	StrToIndex(Harl harl, char *str)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) // Finding which log mode statement matches the str-argument.
		if (levels[i] == str)
			return (print_complaint(harl, i));
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	Harl	harl;
	StrToIndex(harl, argv[1]);
	return (0);
}
