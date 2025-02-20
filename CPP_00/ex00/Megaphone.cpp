#include <iostream>
#include <cctype>
#include <cstring>

int	main(int argc, char **argv)
{
	int	str = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	while (str < argc)
	{
		for (size_t i = 0; i < strlen(argv[str]); i++)
			std::cout << (char)toupper(argv[str][i]);
		std::cout << " ";
		str++;
	}
	std::cout << std::endl;
	return (0);
}
