#ifndef PmergeMeVec_HPP
#define PmergeMeVec_HPP
#include "PmergeMe.hpp"

class PmergeMeVec
{

private:
	// Sorting -> utils
	std::vector<size_t> jacobsthalIndices(size_t n);
	int doInsertion(std::vector<int> &mainChain, const std::vector<int> pending, int blockSize, int k, const std::vector<int> original);
	int setInsertionOrder(std::vector<int> &mainChain, const std::vector<int> pending, std::vector<size_t> &jacSequence, int blockSize, int extraBlocksOverJacobsthal, const std::vector<int> original);
	int insertPendingIntoMain(std::vector<int> &mainChain, const std::vector<int> pending, int blockSize, std::vector<int> originalMain);
	int mergeInsertSortVectorRecursive(std::vector<int> &mainChain, int recursionLvl, int &nmbCmpVec);
	int binarySearch(const std::vector<int> &v, int value, int &cmpCount);
	int findMaxMainIndex(int pendingVal, const std::vector<int> pending, std::vector<int> &mainChain, const std::vector<int> original);

public:
	// Sorting
	void mergeInsertSortVector(int argc, char **argv, int &numCmpVec, std::vector<int> &vec);

	// Constructors / destructor
	PmergeMeVec();
	~PmergeMeVec();
};

#endif