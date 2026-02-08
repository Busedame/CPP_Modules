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
