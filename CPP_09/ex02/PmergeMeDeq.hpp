#ifndef PmergeMeDeq_HPP
#define PmergeMeDeq_HPP
#include "PmergeMe.hpp"

class PmergeMeDeq
{

private:
	// Sorting -> utils
	std::deque<size_t> jacobsthalIndices(size_t n);
	int doInsertion(std::deque<int> &mainChain, const std::deque<int> pending, int blockSize, int k, const std::deque<int> original);
	int setInsertionOrder(std::deque<int> &mainChain, const std::deque<int> pending, std::deque<size_t> &jacSequence, int blockSize, int extraBlocksOverJacobsthal, const std::deque<int> original);
	int insertPendingIntoMain(std::deque<int> &mainChain, const std::deque<int> pending, int blockSize, std::deque<int> originalMain);
	int mergeInsertSortDequeRecursive(std::deque<int> &mainChain, int recursionLvl, int &nmbCmpDeq);
	int binarySearch(const std::deque<int> &v, int value, int &cmpCount);
	int findMaxMainIndex(int pendingVal, const std::deque<int> pending, std::deque<int> &mainChain, const std::deque<int> original);

public:
	// Sorting
	void mergeInsertSortDeque(int argc, char **argv, int &numCmpDeq, std::deque<int> &deq);

	// Constructors / destructor
	PmergeMeDeq();
	~PmergeMeDeq();
};

#endif