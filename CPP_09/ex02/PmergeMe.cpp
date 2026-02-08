#include "PmergeMe.hpp"

/**
 * FUCK JOHNSON:
IF YOU REMEMBER NOTHING ELSE

Pairs → discover winners & losers

Pending → proven losers, never re-compared

Blocks → groups with guaranteed ordering

Doubling → accumulating certainty

Insertion last → cheapest possible placement
 * 
 */

PmergeMe::PmergeMe(): deq(), vec() {}

PmergeMe::PmergeMe(const PmergeMe& oth) : deq(oth.deq), vec(oth.vec) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& oth) {
	if (this != &oth) {
		deq = oth.deq;
		vec = oth.vec;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

/*
====== VEC SORT =======
*/

/*
	1. Takes a vector
	2. Takes one pair at a time -> larger goes in main chain, smaller in pending.
	(If the amount of numbers is odd -> meaning there is a leftover -> it goes in pending)
	3. 
*/
void PmergeMe::mergeInsertSortVector(int argc, char **argv, int& numCmpVec)
{
	// 1. Store input in vector
	storeInputVec(argc, argv, vec);

	// 2. If true, there is nothing to sort
	if (vec.size() <= 1)
		return;

	// 3. Declare vectors
	std::vector<int> tmp = vec;
	std::vector<int> notPart;

	// 4. Step 1 -> Sort pairs, pairs of pairs etc.
	DBG(debugPrintRecursionStart(vec));
	int recLvl = mergeInsertSortVectorRecursive(tmp, 1, numCmpVec);
	DBG(debugPrintRecursionEnd(vec, tmp));

	// 5. Step 2 -> Sort blocks into main and pending
	while (recLvl > 0) {
    	int blockSize = 1 << (recLvl - 1);
		std::vector<int> mainChain;
		std::vector<int> pending;
		std::vector<int> leftover;

		for (size_t i = 0; i < tmp.size(); ++i)
		{
			if (organizeChains(i, blockSize, tmp.size()) == 0)
				mainChain.push_back(tmp[i]);
			else if (organizeChains(i, blockSize, tmp.size()) == 1)
				pending.push_back(tmp[i]);
			else
				leftover.push_back(tmp[i]);
		}

		// Merge and keep track of where each chain is located.
		int posPending = mainChain.size();
		mainChain.insert(mainChain.end(), pending.begin(), pending.end()); // merge main-chain + pending
		//int	posLeftovers = posPending + pending.size();
		mainChain.insert(mainChain.end(), leftover.begin(), leftover.end()); // merge main-chain + pending + leftovers


		tmp = mainChain; // Reassign vec

    	// Step 3: insert each pending block into main (Jacobsthal order)
    	//insertPendingJacobsthal(mainChain, pending);

		// DEBUG PRINT START //
		std::cout << "RECURSION LEVEL: " << recLvl << std::endl;
		std::cout << std::endl;
		std::cout << "Main: " << std::endl;
		for (int i = 0; i < posPending; i++){
			std::cout << tmp[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Pending: " << std::endl;
		for (long unsigned int i = 0; i < pending.size(); i++){
			std::cout << pending[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Leftovers: " << std::endl;
		for (long unsigned int i = 0; i < leftover.size(); i++){
			std::cout << leftover[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Whole string: " << std::endl;
		for (long unsigned int i = 0; i < tmp.size(); i++){
			std::cout << tmp[i] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		// DEBUG PRINT END //

		if (!pending.empty())
			insertPendingIntoMain(mainChain, pending, blockSize);

    	recLvl--;
	}

}

void	PmergeMe::insertPendingIntoMain(std::vector<int>& mainChain, std::vector<int>& pending, int blockSize) {
	int	blockAmount = pending.size() / blockSize;
	std::vector<size_t> jacSequence = jacobsthalIndices(blockAmount + 1);
	std::cout << "Block amount: " << blockAmount << std::endl; // DEBUG
	int mainChainsize = mainChain.size(); // DEBUG
	std::cout << mainChainsize << std::endl; // DEBUG

	if (!jacSequence.empty()) { // DEBUG
		std::cout << "JACOBSTHAL: " << jacSequence[0] << std::endl; // DEBUG
		std::cout << "JACOBSTHAL: " << jacSequence[1] << std::endl; // DEBUG
	} // DEBUG

	size_t prevJacNbr = 1; // This would be b1.
	while (blockAmount > 0) {
		for (long unsigned int i = 0; i < jacSequence.size(); i++) {
			int	currJacNbr = jacSequence[i];
			for (size_t i = currJacNbr; i > prevJacNbr; i--) {
				int blockStart = pending.size() - blockSize * i - 1;
				int blockEnd = pending.size() - i - 1;
				std::cout << blockStart << std::endl;
				std::cout << blockEnd << std::endl;
			}
			prevJacNbr = currJacNbr;
		}
		blockAmount--;
	}
}

int PmergeMe::mergeInsertSortVectorRecursive(std::vector<int> &tmp, int recursionLvl, int& nmbCmpVec)
{
    int blockSize = 1 << (recursionLvl - 1);        // 2^(recursionLvl-1)
    int numBlocks = tmp.size() / blockSize;   // how many full blocks fit in tmp.

    if (numBlocks <= 1) {
        return recursionLvl - 1;
	}
	
	DBG(debugPrintBlockSizeAndRecLvl(blockSize, recursionLvl));

    for (size_t i = 0; i + 2*blockSize <= tmp.size(); i += 2*blockSize)
    {
        int lastFirstBlock  = i + blockSize - 1;
        int lastSecondBlock = i + 2 * blockSize - 1;

		nmbCmpVec++;
		DBG(debugPrintCandidates(tmp[lastFirstBlock], tmp[lastSecondBlock], nmbCmpVec)); 
        if (tmp[lastFirstBlock] > tmp[lastSecondBlock])
        {
            std::swap_ranges(tmp.begin() + i,
                             tmp.begin() + i + blockSize,
                             tmp.begin() + i + blockSize);
        }
		DBG(debugPrintWinnerAndLoser(tmp, tmp[lastSecondBlock], tmp[lastFirstBlock]));
    }

    // Recurse to next level
    return mergeInsertSortVectorRecursive(tmp, recursionLvl + 1, nmbCmpVec);
}

// Generate Jacobsthal indices <= n
std::vector<size_t> PmergeMe::jacobsthalIndices(size_t n)
{
    std::vector<size_t> J;
    size_t j0 = 1, j1 = 3;

    while (j1 <= n) {
        J.push_back(j1);
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }
    return J;
}

void PmergeMe::insertIntoVector(std::vector<int> &sorted, int value)
{
	std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(it, value);
}


/*
====== MAIN ENTRYPOINT =======
*/

int	PmergeMe::entryPoint(int argc, char **argv)
{
	// Parse and store input
	if (parseInput(argc, argv))
		return 1;

	int numCmpVec = 0;
	clock_t start_vec = clock(); // Start time for vec
	mergeInsertSortVector(argc, argv, numCmpVec); 	// Actual sorting for vec
	clock_t end_vec = clock(); 	// End time for vec

	// Start time for deq
	clock_t start_deq = clock();

	// Actual sorting for deq
	//mergeInsertSortDeq();

	// End time for deq
	clock_t end_deq = clock();

	// Print sorted sequence from vec and deq
	printUnsorted(argc, argv);
	printVec(vec);

	// Calculate time spent for vec and deq
	double duration_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6;
	double duration_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1e6;

	// Print time spent for vec and deq
	std::cout << "Time to process a range of " << vec.size() 
		<< " elements with std::vector : " << duration_vec << " us" << std::endl;

	std::cout << "Time to process a range of " << deq.size() 
		<< " elements with std::deque : " << duration_deq << " us" << std::endl;

    return 0;
}
