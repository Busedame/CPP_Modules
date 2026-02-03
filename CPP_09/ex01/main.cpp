#include "RPN.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Usage: ./RPN <expression>" << std::endl;
		return (1);
	}

	const std::string input = argv[1];

	RPN rpn;
	if (rpn.run(input))
		return (1);

	return (0);
}
