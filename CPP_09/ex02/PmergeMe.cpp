#include "PmergeMe.hpp"

/*
	Notes to self:
	- Implement deque.
	- Calculate how many operations are allowed (and if I am within the limit).
*/

/*
====== CONSTRUCTORS AND DESTRUCTOR =======
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
	Generating the Jacobsthal sequence based on how many blocks
	we have.
	For two blocks -> J[0] == 3
	For four blocks -> J[0] == 3, J[1] == 5
	And so forth.
*/
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
	Execute the insertion.
	
	@param cmpCount		How many comparisons are made.
	@param mainEnd		The end position of the current mainChain block (initialized to end of first block).
	@param blockId		k - 2. The current Jacobsthal (but - 2 to fit with indexing that starts counting from 0).
	@param jacPairStart Start position of current pending block.
	@param jacPairEnd	End position of current pending block.

	Compares the END POSITION VALUE of the pending block with the END POSITION VALUE of each mainChain block.
	Iterates through the mainChain in order to compare with each mainChain block.
	Ultimately wants the smaller values to the left, and bigger values to the right.

	If pending block is smaller than a main block, insert pending block to the left of that main block.
	If mainChain reaches the end (meaning pending block is greater than all blocks in mainChain) -> append pending block to the end of mainChain.

	@return How many comparisons were made.
*/
int	PmergeMe::doInsertion(std::vector<int>& mainChain, std::vector<int>& pending, int blockSize, int k)
{
	int		cmpCount = 0;
	int		mainEnd = blockSize - 1;
	int		blockId = k - 2; if (blockId < 0) blockId = 0;
	int		jacPairStart = blockId * blockSize;
	int		jacPairEnd = jacPairStart + blockSize - 1;

	DBG(debugPrintCurrentJacobsthal(pending, k, blockId, jacPairStart, jacPairEnd));

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

/*
	Follows the Jacobsthal sequence for insertion.
	The "current" Jacobsthal number will always start as 3, and then follow the Jacobsthal
	sequence (next one would be 5, 11, 21, etc).
	The "previous" Jacobsthal number will always start as 1, and then get updated depending on the
	value of the "current" Jacobsthal number.

	Example with 6 pending blocks and a blockSize of 2.
	b1 is ignored since it is already in main chain.

	This would be the correct order for insertion:

	 b3		 b2		 b5		 b4		 b7		  b6
	2 5		1 3		4 6		8 10	9 12	11 23

	First round previous would be 1, and current would be 3.
	Insert b3, insert b2

	Second round previous would be 3 and current would be 5.
	Insert b5, insert b4

	Third round we have two redundant blocks. They are added in descending order:
	Insert b7, insert b6

	@return How many comparisons were done.
*/
int	PmergeMe::setInsertionOrder(std::vector<int>& mainChain, std::vector<int>& pending, std::vector<size_t>& jacSequence, int blockSize, int extraBlocksOverJacobsthal)
{
	int		cmpCount = 0;
	size_t	currJac = 3;
	size_t	prevJac = 1;

	// Main loop for Jacobsthal sequence
	for (long unsigned int i = 0; i < jacSequence.size(); i++)
	{
		currJac = jacSequence[i];

		for (size_t k = currJac; k > prevJac; k--)
			cmpCount += doInsertion(mainChain, pending, blockSize, k);
		prevJac = currJac;
	}

	if (extraBlocksOverJacobsthal != 0) {
		for (size_t k = currJac + extraBlocksOverJacobsthal; k > prevJac; k--)
			cmpCount += doInsertion(mainChain, pending, blockSize, k);
	}
	return cmpCount;
}

/*
	Calculates how many blocks exist in pending, calculates where to insert based on 
	Jacobsthal order, and inserts each pending block into main chain.
	
	If only one block exists, it can be inserted right away.
	If two or more blocks exist, the order of insertion is calculated by following the Jacobsthal sequence.
	If the number of blocks is in between two Jacobsthal numbers (e.g. 7 is between 5 and 11), it inserts
	the excess blocks in a descending order.

	@return How many comparisons were done.
*/
int	PmergeMe::insertPendingIntoMain(std::vector<int>& mainChain, std::vector<int>& pending, int blockSize) {

	int					blockAmountInPending = pending.size() / blockSize; // How many blocks are in pending.
	int 				excessBlocks = 0; // If block amount is in between Jacobsthal numbers (e.g. 7 blocks -> more than 5, but less than 11).
	std::vector<size_t> jacSequence = jacobsthalIndices(blockAmountInPending + 1); // Get the Jacobsthal sequence for the pending blocks.
	size_t				k = 1; // First Jacobsthal (initialized to 1, but can also start with 3).
	int					cmpCount = 0; // How many comparisons are done.
	size_t				prevJac = 1; // Previous Jacobsthal number (always initialized to 1).

	// If there is two or more blocks in pending
	if (!jacSequence.empty())
	{
		// If there are more blocks in pending than the maximum Jacobsthal number.
		if (static_cast<size_t>(blockAmountInPending) + 1 > jacSequence.back())
			excessBlocks = blockAmountInPending + 1 - jacSequence.back();

		// If Jacobsthal is 3 (it is two or more blocks present), set k to 3.
		k = jacSequence.front();
	}
	
	// If there is only one block in pending -> it goes straight into main.
	if (prevJac == k)
		cmpCount = doInsertion(mainChain, pending, blockSize, 2);

	// If there is two or more blocks in pending -> insertion order needs to be set first
	else
		cmpCount = setInsertionOrder(mainChain, pending, jacSequence, blockSize, excessBlocks);

	return cmpCount;
}

/*
	Sorts the values into elements. This means pairs (recursionLvl 1), pairs of pairs (recursionLvl 2), and so forth.
	Two elements are compared at a time, and if the first one is bigger, their positions are swapped.
	When comparing two elements, the LAST value of the elements are getting compared.

	Example with blockSize of 2 and these two elements: 2 5 4 3
	Only 5 and 3 are compared.
	Since 5 is bigger than 3, the blocks are swapped.
	New order: 4 3 2 5

	@return Max recursion level reached
*/
int PmergeMe::mergeInsertSortVectorRecursive(std::vector<int> &tmp, int recursionLvl, int& nmbCmpVec)
{
    int blockSize = 1 << (recursionLvl - 1); // 2^(recursionLvl-1)
    int numBlocks = tmp.size() / blockSize; // How many full blocks can fit in tmp.

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

/*
	1. Stores input.
	2. If only one value in input -> there is nothing to sort.
	3. Sort part 1: recursively making 'a' and 'b' blocks.
	4. For each recursion level done:
		- Sort part 2: sort into main, pending and leftover chain.
		- Sort part 3: insert pending into main using the Jacobsthal sequence to determine order.

*/
void PmergeMe::mergeInsertSortVector(int argc, char **argv, int& numCmpVec)
{
	// 1. Store input in vector
	storeInputVec(argc, argv, vec);

	// 2. If true, there is nothing to sort
	if (vec.size() <= 1)
		return;

	// 3. Sort part 1
	DBG(debugPrintRecursionStart(vec)); // DEBUG
	int recLvl = mergeInsertSortVectorRecursive(vec, 1, numCmpVec);
	DBG(debugPrintRecursionEnd(vec, vec)); // DEBUG

	std::vector<int> mainChain;
	std::vector<int> pending;
	std::vector<int> leftover;

	// 5. Sort part 2 and 3
	while (recLvl > 0) {

		DBG(debugPrintRecursionLevel(recLvl)); // DEBUG

    	int blockSize = 1 << (recLvl - 1);

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

		DBG(debugPrintMainPendingLeftover(mainChain, pending, leftover)); // DEBUG
	
		if (!pending.empty())
			numCmpVec += insertPendingIntoMain(mainChain, pending, blockSize); // Insert pending into main chain.
		if (!leftover.empty())
			mainChain.insert(mainChain.end(), leftover.begin(), leftover.end()); // Append leftovers to main chain.
	
		vec = mainChain; // Reassign vec

		DBG(debugPrintMainAfterInsertion(vec)); // DEBUG

		mainChain.clear(); pending.clear(); leftover.clear(); // Clear contents each round.
    	recLvl--; // Go down one recursion level.
	}
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

	clock_t start_deq = clock(); // Start time for deq
	//mergeInsertSortDeq(); // Actual sorting for deq
	clock_t end_deq = clock(); // End time for deq

	// Print sorted sequence from vec and deq
	printUnsorted(argc, argv);
	printVec(vec);

	// THIS ONLY WORKS WITHOUT C++ 1998 (checks if it is actually sorted).
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
