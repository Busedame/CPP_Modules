#include "debug.hpp"

void	debugPrintRecursionStart(std::vector<int>& original) {
	std::cout << "==== RECURSION START ====" << std::endl;
	std::cout << "Original input:" << std::endl;
	for (size_t i = 0; i < original.size(); i++){
		std::cout << original[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void	debugPrintRecursionEnd(std::vector<int>& original, std::vector<int>& afterRec) {
	std::cout << "==== RECURSION END ====" << std::endl;
	std::cout << "Original input:" << std::endl;
	for (size_t i = 0; i < original.size(); i++){
		std::cout << original[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Input after recursion:" << std::endl;
	for (size_t i = 0; i < afterRec.size(); i++){
		std::cout << afterRec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void	debugPrintBlockSizeAndRecLvl(const int blockSize, const int recLvl) {
	std::cout << "CURRENT RECURSION LEVEL: " << recLvl << std::endl;
	std::cout << "CURRENT BLOCKSIZE: " << blockSize << std::endl;
	std::cout << std::endl;
}

void	debugPrintCandidates(int lastFirstBlock, int lastSecondBlock, int nmbCmp) {
	std::cout << "ROUND " << nmbCmp << std::endl;
	std::cout << "Current candidates: [" << lastFirstBlock  << ", " << lastSecondBlock << "]" << std::endl;

}

void	debugPrintWinnerAndLoser(std::vector<int>& vec, const int winner, const int loser) {
	std::cout << "Winner: " << winner << std::endl;
	std::cout << "Loser: " << loser << std::endl;
	std::cout << "Input state after changes:" << std::endl;
	for (size_t i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void	debugPrintCurrentJacobsthal(std::vector<int>& pending, int k, int blockId, int jacPairStart, int jacPairEnd)
{
	std::cout << "Current Jacobsthal: " << k << std::endl;
	std::cout << "At which pos does block b" << blockId + 2 << " start in pending?: " << jacPairStart << std::endl;
	std::cout << "At which pos does block b" << blockId + 2 << " end in pending?: " << jacPairEnd << std::endl;
	std::cout << "Which (last) value does block b" << blockId + 2 << " have in pending?: " << pending[jacPairEnd] << std::endl;
	std::cout << std::endl;
}

void	debugPrintMainPendingLeftover(std::vector<int>& mainChain, std::vector<int>& pending, std::vector<int>& leftover)
{
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
}

void	debugPrintMainAfterInsertion(std::vector<int>& vec)
{
	std::cout << "Vector after insertion: " << std::endl;
	for (long unsigned int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void	debugPrintRecursionLevel(int recLvl)
{
	std::cout << "RECURSION LVL: " << recLvl << std::endl;
	std::cout << std::endl;
}
