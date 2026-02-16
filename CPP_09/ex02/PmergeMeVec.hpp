#ifndef PmergeMeVec_HPP
# define PmergeMeVec_HPP
# include "PmergeMe.hpp"

class	PmergeMeVec {

	private:
		// Sorting -> utils
		std::vector<size_t>	jacobsthalIndices(size_t n);
		int					doInsertion(std::vector<int>& mainChain, std::vector<int>& pending, int blockSize, int k);
		int					setInsertionOrder(std::vector<int>& mainChain, std::vector<int>& pending, std::vector<size_t>& jacSequence, int blockSize, int extraBlocksOverJacobsthal);
		int					insertPendingIntoMain(std::vector<int>& mainChain, std::vector<int>& pending, int blockSize);
		int					mergeInsertSortVectorRecursive(std::vector<int> &mainChain, int recursionLvl, int& nmbCmpVec);
		int					binarySearch(const std::vector<int>& v, int value, int& cmpCount);
		int 				computeUsableMainRange(int k, size_t mainChainSize, int blockSize);

		size_t 				initialMainBlocksSnapshot;


	public:
		// Sorting
		void				mergeInsertSortVector(int argc, char **argv, int& numCmpVec, std::vector<int>& vec);

		// Constructors / destructor
		PmergeMeVec();
		~PmergeMeVec();

};

#endif