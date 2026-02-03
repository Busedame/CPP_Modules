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
int	RPN::handleOperator(char c) {
	if (stack.size() < 2)
		return 1;

	int first = stack.top();
	stack.pop();
	int second = stack.top();
	stack.pop();

	int result;

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

	stack.push(result);
	return 0;
}

/*
====== MAIN CLASS FUNCTION =======
*/

int	RPN::run(const std::string& input) {
	std::vector<std::string> tokens = split(input, ' ');

	for (size_t i = 0; i < tokens.size(); i++) {
		if (tokens[i].size() != 1) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
		if (isdigit(tokens[i][0])) {
			stack.push(static_cast<int>(atol(tokens[i].c_str())));
		}
		if (isOperator(tokens[i][0])) {
			if (handleOperator(tokens[i][0])) {
				std::cerr << "Error" << std::endl;
				return 1;
			}
		}
	}

	if (stack.size() != 1) {
		std::cout << "Error" << std::endl;
		return 1;
	}

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
		tokens.push_back(item);
	}

	return tokens;
}
