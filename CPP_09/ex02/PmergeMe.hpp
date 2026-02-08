#ifndef PmergeMe_HPP
# define PmergeMe_HPP
# include <iostream>
# include <stack>
# include <vector>
# include <sstream>
# include <algorithm>
# include <deque>
# include <ctime>
# include <climits>

# include "debug.hpp"

class	PmergeMe {
	private:
		// Containers
		std::deque<int> deq;
		std::vector<int> vec;

		// Parse and store input
		int		parseInput(int argc, char **argv);
		void	storeInputVec(int argc, char **argv);
		void	storeInputDeq(int argc, char **argv);

		// Printing
		void printVec(void);
		void printDeq(void);
		void printUnsorted(int argc, char **argv);

		// Sorting
		void mergeInsertSortVector(int argc, char **argv, int& numCmpVec);

		// Sorting -> utils
		int mergeInsertSortVectorRecursive(std::vector<int> &mainChain, int recursionLvl, int& nmbCmpVec);
		
		void insertIntoVector(std::vector<int> &sorted, int value);
		std::vector<size_t> jacobsthalIndices(size_t n);
		void insertPendingJacobsthal(std::vector<int>& mainChain, std::vector<int>& pending);
		std::vector<size_t> buildInsertionOrder(size_t n);
		int	organizeChains(int index, int blockSize, int totalSize);
		void	insertPendingIntoMain(std::vector<int>& mainChain, std::vector<int>& pending, int blockSize);


	public:
		PmergeMe();
		PmergeMe(const PmergeMe& oth);
		PmergeMe&	operator=(const PmergeMe& oth);
		~PmergeMe();

		// Main entrypoint
		int	entryPoint(int argc, char **argv);

};

#endif