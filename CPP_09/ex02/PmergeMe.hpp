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

		// Sorting
		void				mergeInsertSortVector(int argc, char **argv, int& numCmpVec);

		// Sorting -> utils
		int					mergeInsertSortVectorRecursive(std::vector<int> &mainChain, int recursionLvl, int& nmbCmpVec);
		std::vector<size_t>	jacobsthalIndices(size_t n);
		int					insertPendingIntoMain(std::vector<int>& mainChain, std::vector<int>& pending, int blockSize);
		int					doInsertion(std::vector<int>& mainChain, std::vector<int>& pending, int blockSize, int k);


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