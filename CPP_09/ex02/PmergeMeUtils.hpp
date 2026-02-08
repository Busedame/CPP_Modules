#ifndef PMERGEMEUTILS_HPP
# define PMERGEMEUTILS_HPP
# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <climits>

// Printing
	void	printVec(std::vector<int>& vector);
	void	printDeq(std::deque<int>& deque);
	void	printUnsorted(int argc, char **argv);

// Parsing
	int		parseInput(int argc, char **argv);

// Sorting utils
	int		organizeChains(int index, int blockSize, int totalSize);

// Parse and store input
	void	storeInputVec(int argc, char **argv, std::vector<int>& vec);
	void	storeInputDeq(int argc, char **argv, std::deque<int>& deq);

#endif
