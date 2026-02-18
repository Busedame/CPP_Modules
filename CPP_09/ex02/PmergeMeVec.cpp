#include "PmergeMeVec.hpp"

/*
====== CONSTRUCTORS AND DESTRUCTOR =======
*/

PmergeMeVec::PmergeMeVec() {}

PmergeMeVec::~PmergeMeVec() {}

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
std::vector<size_t> PmergeMeVec::jacobsthalIndices(size_t n)
{
	std::vector<size_t> J;
	size_t j0 = 1, j1 = 1;

	while (j1 <= n)
	{
		J.push_back(j1);
		size_t next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}
	return J;
}

/*
	Doing binary search on the LAST values of main chain blocks.
	Starts from middle.
	If value is smaller than middle -> take the left half.
	If value is greater than middle value -> take the right half.
	Repeats until it finds the correct position, and returns that position.

	@return Returns the mainChain BLOCK index (not the position of the value).
*/
int PmergeMeVec::binarySearch(const std::vector<int> &v, int value, int &cmpCount)
{
	int left = 0;
	int right = v.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		cmpCount++;

		if (value < v[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

/*
	Computes the number of maximum main index that can be used in the insertion.
*/
int PmergeMeVec::findMaxMainIndex(int pendingVal, std::vector<int> &pending, std::vector<int> &mainChain, int blockSize, const std::vector<int> original)
{
	// Sort the original vector
	std::vector<int> originalMain;
	std::vector<int> originalPending;

	for (size_t i = 0; i < original.size(); i++)
	{
		int chainType = organizeChains(i, blockSize, original.size());
		if (chainType == 0)
			originalMain.push_back(original[i]);
		else if (chainType == 1)
			originalPending.push_back(original[i]);
	}

	size_t i = 0;
	while (i < pending.size())
	{
		if (pendingVal == pending[i])
			break;
		i++;
	}

	int correspondingMainValue;

	if (i < originalMain.size())
		correspondingMainValue = originalMain[i];
	else
		return mainChain.size() - 1;

	i = 0;
	while (i < mainChain.size())
	{
		if (correspondingMainValue == mainChain[i])
			break;
		i++;
	}
	return i;
}

/*
	Execute the insertion.

	@param cmpCount		How many comparisons are made.
	@param blockId		k - 2. The current Jacobsthal (but - 2 to fit with indexing that starts counting from 0).
	@param jacPairStart Start position of current pending block.
	@param jacPairEnd	End position of current pending block.
	@param mainVals		Block indexes in mainChain
	@param insertPos	At which position to insert in mainChain.

	Compares the END POSITION VALUE of the pending block with the END POSITION VALUE of the mainChain blocks.
	Starts from middle of mainChain and uses binary search do determine the insertion position.

	@return How many comparisons were made.
*/
int PmergeMeVec::doInsertion(std::vector<int> &mainChain, std::vector<int> &pending, int blockSize, int k, const std::vector<int> original)
{
	int cmpCount = 0;
	int blockId = k - 1;
	int jacPairStart = blockId * blockSize;
	int jacPairEnd = jacPairStart + blockSize - 1;

	std::vector<int> mainVals;
	int pendingVal = pending[jacPairEnd];

	if (blockId == 0)
	{
		mainChain.insert(mainChain.begin(), pending.begin() + jacPairStart, pending.begin() + jacPairEnd + 1);
		return (0);
	}

	// Figure out how many main blocks we are allowed to compare with based on INITIAL main chain (exit early if none).
	size_t maxMainIndex = findMaxMainIndex(pendingVal, pending, mainChain, blockSize, original);

	std::cout << "Max main index: " << maxMainIndex << std::endl;
	std::cout << "Main chain length: " << mainChain.size() << std::endl;
	// Build mainVals from the current mainChain's block-ends.
	// START FROM SECOND MAINVAL
	// Set upper bound to be the larger main

	for (size_t i = static_cast<size_t>(blockSize) - 1; i <= maxMainIndex; i += static_cast<size_t>(blockSize))
	{
		mainVals.push_back(mainChain[i]);
	}

	// debugPrintCurrentJacobsthal(pending, k, blockId, jacPairStart, jacPairEnd);

	// Do binary search to find insertion position
	int insertBlockIndex = binarySearch(mainVals, pendingVal, cmpCount);
	int insertPos = insertBlockIndex * blockSize;

	// Insert pending into mainChain.
	mainChain.insert(mainChain.begin() + insertPos, pending.begin() + jacPairStart, pending.begin() + jacPairEnd + 1);

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
int PmergeMeVec::setInsertionOrder(std::vector<int> &mainChain, std::vector<int> &pending, std::vector<size_t> &jacSequence, int blockSize, int extraBlocksOverJacobsthal, const std::vector<int> original)
{
	int cmpCount = 0;
	size_t currJac = 1;
	size_t prevJac = 0;

	// Main loop for Jacobsthal sequence
	for (long unsigned int i = 0; i < jacSequence.size(); i++)
	{
		currJac = jacSequence[i];
		std::cout << "Current jacobsthal: " << currJac << std::endl;

		for (size_t k = currJac; k > prevJac; k--)
			cmpCount += doInsertion(mainChain, pending, blockSize, k, original);
		prevJac = currJac;
	}

	if (extraBlocksOverJacobsthal != 0)
	{
		for (size_t k = currJac + extraBlocksOverJacobsthal; k > prevJac; k--)
			cmpCount += doInsertion(mainChain, pending, blockSize, k, original);
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
int PmergeMeVec::insertPendingIntoMain(std::vector<int> &mainChain, std::vector<int> &pending, int blockSize, const std::vector<int> originalMain)
{

	int blockAmountInPending = pending.size() / blockSize; // How many blocks are in pending.
	int excessBlocks = 0;
	std::vector<size_t> jacSequence = jacobsthalIndices(blockAmountInPending);
	int cmpCount = 0;

	// If there is two or more blocks in pending
	if (!jacSequence.empty())
	{
		if (static_cast<size_t>(blockAmountInPending) > jacSequence.back())
			excessBlocks = blockAmountInPending - jacSequence.back();
	}

	// If there is only one block in pending
	if (blockAmountInPending == 1)
		cmpCount = doInsertion(mainChain, pending, blockSize, 1, originalMain);

	// If there is two or more blocks in pending
	else
		cmpCount = setInsertionOrder(mainChain, pending, jacSequence, blockSize, excessBlocks, originalMain);

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
int PmergeMeVec::mergeInsertSortVectorRecursive(std::vector<int> &tmp, int recursionLvl, int &nmbCmpVec, std::vector<std::vector<int>> &originalChains)
{
	int blockSize = 1 << (recursionLvl - 1); // 2^(recursionLvl-1)
	int numBlocks = tmp.size() / blockSize;	 // How many full blocks can fit in tmp.

	if (numBlocks <= 1)
	{
		return recursionLvl - 1;
	}

	DBG(debugPrintBlockSizeAndRecLvl(blockSize, recursionLvl));

	for (size_t i = 0; i + 2 * blockSize - 1 < tmp.size(); i += 2 * blockSize)
	{
		int lastFirstBlock = i + blockSize - 1;
		int lastSecondBlock = i + 2 * blockSize - 1;

		DBG(debugPrintCandidates(tmp[lastFirstBlock], tmp[lastSecondBlock], recursionLvl));
		if (tmp[lastFirstBlock] > tmp[lastSecondBlock])
		{
			nmbCmpVec++;
			std::swap_ranges(tmp.begin() + i,
							 tmp.begin() + i + blockSize,
							 tmp.begin() + i + blockSize);
		}
		DBG(debugPrintWinnerAndLoser(tmp, tmp[lastSecondBlock], tmp[lastFirstBlock]));
	}
	originalChains.push_back(tmp);

	// Recurse to next level
	return mergeInsertSortVectorRecursive(tmp, recursionLvl + 1, nmbCmpVec, originalChains);
}

/*
	1. Stores input.
	2. If only one value in input -> there is nothing to sort.
	3. Sort part 1: recursively making 'a' and 'b' blocks.
	4. For each recursion level done:
		- Sort part 2: sort into main, pending and leftover chain.
		- Sort part 3: insert pending into main using the Jacobsthal sequence to determine order.

*/
void PmergeMeVec::mergeInsertSortVector(int argc, char **argv, int &numCmpVec, std::vector<int> &vec)
{
	// 1. Store input in vector
	storeInputVec(argc, argv, vec);

	// 2. If true, there is nothing to sort
	if (vec.size() <= 1)
		return;

	// Stores the whole original sequence for each recursion level
	std::vector<std::vector<int>> originalChains;

	// 3. Sort part 1
	DBG(debugPrintRecursionStart(vec)); // DEBUG
	int recLvl = mergeInsertSortVectorRecursive(vec, 1, numCmpVec, originalChains);
	DBG(debugPrintRecursionEnd(vec, vec)); // DEBUG

	std::cout << "Number of comparisons after recursion: " << numCmpVec << std::endl;

	std::vector<int> mainChain;
	std::vector<int> pending;
	std::vector<int> leftover;

	// 5. Sort part 2 and 3
	while (recLvl > 0)
	{

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

		debugPrintMainPendingLeftover(mainChain, pending, vec); // DEBUG

		const std::vector<int> original = vec;

		if (!pending.empty())
			numCmpVec += insertPendingIntoMain(mainChain, pending, blockSize, original); // Insert pending into main chain.
		if (!leftover.empty())
			mainChain.insert(mainChain.end(), leftover.begin(), leftover.end()); // Append leftovers to main chain.

		vec = mainChain; // Reassign vec

		DBG(debugPrintMainAfterInsertion(vec)); // DEBUG

		mainChain.clear();
		pending.clear();
		leftover.clear(); // Clear contents each round.
		recLvl--;		  // Go down one recursion level.
	}
}
