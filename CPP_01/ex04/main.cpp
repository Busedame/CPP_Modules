#include "Replace.hpp"

int	main(int argc, char **argv)
{
	// Checking if argument count is correct.
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <what_should_be_replaced> <replacement>" << std::endl;
		return (1);
	}

	// Assigning the argv array to different variable names, for better readability.
	const char* InfileName = argv[1];
	const char* OutfileName = "outfile";
	std::string S1 = argv[2];
	std::string S2 = argv[3];
	std::string Line;

	// Opens the file <InfileName> in read-mode, and stores the file descriptor in InfileFD.
	std::ifstream InfileFD(InfileName);
	if (!InfileFD)
	{
		std::cerr << "Error: Could not open the file '" << InfileName << "'. Please make sure it exists." << std::endl;
		return (2);
	}

	// Opens the file <OutfileName> in write-mode, and stores the file descriptor in OutfileFD.
	std::ofstream OutfileFD(OutfileName);
	if (!OutfileFD)
	{
		std::cerr << "Error: Could not create the output file." << std::endl;
		InfileFD.close();
		return (3);
	}

	// Reading through the infile line by line, and replaces each occurence of s1 with s2. 
	while (std::getline(InfileFD, Line))
		OutfileFD << ft_replace(Line, S1, S2) << std::endl;
	
	// Closing the file descriptors.
	InfileFD.close();
	OutfileFD.close();
}
