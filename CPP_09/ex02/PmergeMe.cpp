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

	// 4. Step 1 -> Sort pairs, pairs of pairs etc.
	DBG(debugPrintRecursionStart(vec));
	int recLvl = mergeInsertSortVectorRecursive(vec, 1, numCmpVec);
	DBG(debugPrintRecursionEnd(vec, vec));

	// 5. Step 2 -> Sort blocks into main and pending
	while (recLvl > 0) {
    	int blockSize = 1 << (recLvl - 1);
		std::vector<int> mainChain;
		std::vector<int> pending;
		std::vector<int> leftover;
	
		std::cout << "RECURSION LEVEL: " << recLvl << std::endl;
		std::cout << std::endl;


		for (size_t i = 0; i < vec.size(); i++)
		{
			int chain = organizeChains(i, blockSize, vec.size());
			if (chain == 0)
				mainChain.push_back(vec[i]);
			else if (chain == 1)
				pending.push_back(vec[i]);
			else
				leftover.push_back(vec[i]);
		}


		// DEBUG PRINT START //
		std::cout << "Main: " << std::endl;
		for (long unsigned int i = 0; i < mainChain.size(); i++){
			std::cout << mainChain[i] << " ";
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
		// DEBUG PRINT END //
	
		if (!pending.empty())
			numCmpVec += insertPendingIntoMain(mainChain, pending, blockSize);
		if (!leftover.empty())
			mainChain.insert(mainChain.end(), leftover.begin(), leftover.end()); // merge main-chain + leftovers
	
		vec = mainChain; // Reassign vec

		// DEBUG PRINT START //
		std::cout << "Main after adding: " << std::endl;
		for (long unsigned int i = 0; i < vec.size(); i++){
			std::cout << vec[i] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		// DEBUG PRINT END //

    	recLvl--;
	}

}

int	PmergeMe::doInsertion(std::vector<int>& mainChain, std::vector<int>& pending, int blockSize, int k)
{
	int		cmpCount = 0;
	int		mainEnd = blockSize - 1;
	int		blockId = k - 2; if (blockId < 0) blockId = 0;
	int		jacPairStart = blockId * blockSize;
	int		jacPairEnd = jacPairStart + blockSize - 1;

	std::cout << "Jacobsthal decrement: " << k << std::endl;
	std::cout << "At which pos does block b" << blockId + 2 << " start in pending?: " << jacPairStart << std::endl;
	std::cout << "At which pos does block b" << blockId + 2 << " end in pending?: " << jacPairEnd << std::endl;

	while (1)
	{
		cmpCount++;

		if (static_cast<long unsigned int>(mainEnd) >= mainChain.size())
		{
			if (blockSize == 1)
				mainChain.insert(mainChain.end(), pending[jacPairStart]);
			else {
				mainChain.insert(
					mainChain.end(),
					pending.begin() + jacPairStart,
					pending.begin() + jacPairEnd + 1
				);
			}
			break ;
		}

		int pendingLast = pending[jacPairEnd];
		int	mainLast = mainChain[mainEnd];

		if (pendingLast < mainLast)
		{
			int insertPos = mainEnd - (blockSize - 1);

			if (blockSize == 1)
				mainChain.insert(mainChain.begin() + insertPos, pending[jacPairStart]);
			else {
				mainChain.insert(
    				mainChain.begin() + insertPos,
    				pending.begin() + jacPairStart,
    				pending.begin() + jacPairEnd + 1
				);
			}
			break ;

		}
		mainEnd += blockSize;
	}
	return cmpCount;
}

int	PmergeMe::insertPendingIntoMain(std::vector<int>& mainChain, std::vector<int>& pending, int blockSize) {

	int					blockAmountInPending = pending.size() / blockSize; // How many blocks are in pending
	//int					blockAmountInMain = mainChain.size() / blockSize; // How many blocks are in main
	int 				extraBlocksOverJacobsthal = 0; // If above jacobsthal number (5 means up to b6 exists)
	std::vector<size_t> jacSequence = jacobsthalIndices(blockAmountInPending + 1); // Get the Jacobsthal sequence for the pending blocks
	size_t				k = 1; // First Jacobsthal (1, can also start with 3).
	int					cmpCount = 0;

	// If there are more blocks in pending than the maximum Jacobsthal number.
	if (!jacSequence.empty())
	{
		if (static_cast<size_t>(blockAmountInPending) + 1 > jacSequence.back())
			extraBlocksOverJacobsthal = blockAmountInPending + 1 - jacSequence.back();
	}

	// If Jacobsthal is 3 (it is two ore more blocks present), set k to 3 and corresponding position to 1 (second).
	if (!jacSequence.empty()) {
		k = jacSequence.front();
	}

	size_t	prevJac = 1; // Previous Jacobsthal number was 1
	size_t	currJac = k; // Current one will always start as 3 or 1
	
	if (prevJac == currJac) // Only one block in pending -> it goes straight into main.
	{
		cmpCount += doInsertion(mainChain, pending, blockSize, 2);
		return cmpCount;
	}

	for (long unsigned int i = 0; i < jacSequence.size(); i++)
	{
		currJac = jacSequence[i];

		//std::cout << "JACOBSTHAL ROUND " << currJac << " START!" << std::endl;
		std::cout << std::endl;

		for (size_t k = currJac; k > prevJac; k--)
		{
			cmpCount += doInsertion(mainChain, pending, blockSize, k);
			//printVec(mainChain);
		}
		prevJac = currJac;
	}

	if (extraBlocksOverJacobsthal != 0) {
		for (size_t k = currJac + extraBlocksOverJacobsthal; k > prevJac; k--)
		{
			cmpCount += doInsertion(mainChain, pending, blockSize, k);
			//printVec(mainChain);
		}
	}
	return cmpCount;
}

int PmergeMe::mergeInsertSortVectorRecursive(std::vector<int> &tmp, int recursionLvl, int& nmbCmpVec)
{
    int blockSize = 1 << (recursionLvl - 1);        // 2^(recursionLvl-1)
    int numBlocks = tmp.size() / blockSize;   // how many full blocks fit in tmp.

    if (numBlocks <= 1) {
        return recursionLvl - 1;
	}
	
	DBG(debugPrintBlockSizeAndRecLvl(blockSize, recursionLvl));

    for (size_t i = 0; i + 2*blockSize - 1 < tmp.size(); i += 2*blockSize)
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

	//bool sorted = std::is_sorted(vec.begin(), vec.end());
	//std::cout << "Is sorted?: " << sorted << std::endl;

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
