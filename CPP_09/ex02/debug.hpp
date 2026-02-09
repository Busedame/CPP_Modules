#ifndef DEBUG_HPP
# define DEBUG_HPP
# include <iostream>
# include <vector>

#ifdef DEBUG
# define DBG(code) code
#else
# define DBG(code)
#endif

void	debugPrintRecursionStart(std::vector<int>& original);
void	debugPrintRecursionEnd(std::vector<int>& original, std::vector<int>& afterRec);
void	debugPrintBlockSizeAndRecLvl(const int blockSize, const int recLvl);
void	debugPrintCandidates(int lastFirstBlock, int lastSecondBlock, int nmbCmp);
void	debugPrintWinnerAndLoser(std::vector<int>& vec, const int winner, const int loser);
void	debugPrintCurrentJacobsthal(std::vector<int>& pending, int k, int blockId, int jacPairStart, int jacPairEnd);
void	debugPrintMainPendingLeftover(std::vector<int>& mainChain, std::vector<int>& pending, std::vector<int>& leftover);
void	debugPrintMainAfterInsertion(std::vector<int>& vec);
void	debugPrintRecursionLevel(int recLvl);

#endif
