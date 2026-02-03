#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./btc <file>" << std::endl;
		return (1);
	}

	BitcoinExchange btc;

	// Assigning the argv array to different variable names, for better readability.
	const char* fileName = argv[1];

	// Opens the file in read-mode, and stores the file descriptor in fileFd.
	std::ifstream fileFd(fileName);
	if (!fileFd) {
		std::cerr << "Error: Could not open the file '" << fileName << "'" << std::endl;
		return (2);
	}

	// Opens the file in read-mode, and stores the file descriptor in fileFd.
	std::ifstream csvFileFd("data.csv");
	if (!csvFileFd) {
		std::cerr << "Error: Could not open the file 'data.csv'" << std::endl;
		return (3);
	}

	// Parse input
	btc.run(fileFd, csvFileFd);

	// Closing the file descriptor.
	fileFd.close();
	csvFileFd.close();

	return (0);
}
