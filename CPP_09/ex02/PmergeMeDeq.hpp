#ifndef PmergeMeDeq_HPP
# define PmergeMeDeq_HPP
# include "PmergeMe.hpp"

class	PmergeMeDeq {

	private:
		// Sorting -> utils
		std::deque<size_t>	jacobsthalIndices(size_t n);
		int					doInsertion(std::deque<int>& mainChain, std::deque<int>& pending, int blockSize, int k);
		int					setInsertionOrder(std::deque<int>& mainChain, std::deque<int>& pending, std::deque<size_t>& jacSequence, int blockSize, int extraBlocksOverJacobsthal);
		int					insertPendingIntoMain(std::deque<int>& mainChain, std::deque<int>& pending, int blockSize);
		int					mergeInsertSortDequeRecursive(std::deque<int> &mainChain, int recursionLvl, int& nmbCmpVec);
		int 				computeUsableMainRange(int k, size_t mainChainSize, int blockSize);
		int 				binarySearch(const std::deque<int>& v, int value, int& cmpCount);

		size_t				initialMainBlocksSnapshot;
	public:
		// Main entrypoint
		void 				mergeInsertSortDeque(int argc, char **argv, int& numCmpdeq, std::deque<int>& deq);

		// Constructors / destructor
		PmergeMeDeq();
		~PmergeMeDeq();
};

#endif