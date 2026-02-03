#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <vector>
# include <sstream>
# include <algorithm>

class	RPN {
	private:
		std::stack<int> stack;
	public:
		RPN();
		RPN(const RPN& oth);
		RPN&	operator=(const RPN& oth);
		~RPN();

		int	run(const std::string& input);

		bool	isOperator(char c);
		int		handleOperator(char c);
};

// Outside class utils
bool isSpace(char c);
std::vector<std::string> split(const std::string& str, char delimiter);

#endif