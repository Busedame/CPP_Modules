#include "RPN.hpp"

RPN::RPN(): stack() {}

RPN::RPN(const RPN& oth) : stack(oth.stack) {}

RPN& RPN::operator=(const RPN& oth) {
	if (this != &oth) {
		stack = oth.stack;
	}
	return (*this);
}

RPN::~RPN() {}

/*
====== EQUATION LOGIC =======
*/

// Handles equation
int	RPN::doEquation(char c) {

	// If two numbers are not present, equation is not possible.
	if (stack.size() < 2)
		return 1;

	// Store the two top numbers in the stack and pop them from stack.
	int first = stack.top();
	stack.pop();
	int second = stack.top();
	stack.pop();

	// To store result.
	int result;

	// Find correct operator, do equation and store in result.
	switch (c)
	{
		case '+':
			result = second + first;
			break;
		case '-':
			result = second - first;
			break;
		case '*':
			result = second * first;
			break;
		case '/':
			if (first == 0)
				return 1;
			result = second / first;
			break;
	}

	// Push result to stack
	stack.push(result);

	return 0;
}

/*
====== MAIN CLASS FUNCTION =======
*/

int	RPN::run(const std::string& input) {
	std::vector<std::string> tokens = split(input, ' ');

	for (size_t i = 0; i < tokens.size(); i++) {

		// If token contains more than one character, throw an error.
		if (tokens[i].size() != 1) {
			std::cerr << "Error" << std::endl;
			return 1;
		}

		// Handles operand and operator - and if neither of these -> throw an error.
		if (isdigit(tokens[i][0])) {
			stack.push(tokens[i][0] - '0');
		}
		else if (isOperator(tokens[i][0])) {
			if (doEquation(tokens[i][0])) {
				std::cerr << "Error" << std::endl;
				return 1;
			}
		}
		else {
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}

	// Stack should only contain one number by the end.
	if (stack.size() != 1) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	// Print out the number remaining in the stack
	std::cout << stack.top() << std::endl;

	return 0;
}

/*
====== UTILS =======
*/

// Evaluates to true if c is: + - * / 
bool	RPN::isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

/*
====== OUTSIDE CLASS UTILS =======
*/

bool isSpace(char c) {
    return std::isspace(static_cast<unsigned char>(c));
}

std::vector<std::string> split(const std::string& str, char delimiter)
{
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string item;

	while (std::getline(ss, item, delimiter)) {
		// Remove spaces
		item.erase(std::remove_if(item.begin(), item.end(), isSpace), item.end());

		// Add item to tokens
		if (!item.empty())
			tokens.push_back(item);
	}

	return tokens;
}
