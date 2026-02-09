#ifndef PmergeMe_HPP
# define PmergeMe_HPP
# include <iostream>
# include <stack>
# include <vector>
# include <sstream>
# include <algorithm>
# include <deque>
# include <ctime>

# include "debug.hpp"
# include "PmergeMeUtils.hpp"

class	PmergeMe {

	private:
		// Containers
		std::deque<int> deq;
		std::vector<int> vec;

		// Sorting -> utils
		std::vector<size_t>	jacobsthalIndices(size_t n);
		int					doInsertion(std::vector<int>& mainChain, std::vector<int>& pending, int blockSize, int k);
		int					setInsertionOrder(std::vector<int>& mainChain, std::vector<int>& pending, std::vector<size_t>& jacSequence, int blockSize, int extraBlocksOverJacobsthal);
		int					insertPendingIntoMain(std::vector<int>& mainChain, std::vector<int>& pending, int blockSize);
		int					mergeInsertSortVectorRecursive(std::vector<int> &mainChain, int recursionLvl, int& nmbCmpVec);

		// Sorting
		void				mergeInsertSortVector(int argc, char **argv, int& numCmpVec);

	public:
		// Main entrypoint
		int					entryPoint(int argc, char **argv);

		// Constructors / destructor
		PmergeMe();
		PmergeMe(const PmergeMe& oth);
		PmergeMe&	operator=(const PmergeMe& oth);
		~PmergeMe();

};

#endif