#include "PmergeMeUtils.hpp"

/*
====== PRINTING =======
*/

void printVec(std::vector<int>& vector)
{
	std::cout << "After:\t";
	for (long unsigned int i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}

void printDeq(std::deque<int>& deque)
{
	std::cout << "After:\t";
	for (long unsigned int i = 0; i < deque.size(); i++)
		std::cout << deque[i] << " ";
	std::cout << std::endl;
}

void printUnsorted(int argc, char **argv)
{
	std::cout << "Before:\t";
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
}

/*
====== PARSING=======
*/

int parseInput(int argc, char **argv)
{
    std::vector<int> tmp;
    for (int arg = 1; arg < argc; arg++) {
        char* str = argv[arg];

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] < '0' || str[i] > '9') {
                std::cerr << "Error" << std::endl;
                return 1;
            }
        }

        long l = atol(str);
        if (l > INT_MAX || l < INT_MIN) {
            std::cerr << "Error" << std::endl;
            return 1;
        }

        int num = static_cast<int>(l);

        if (std::find(tmp.begin(), tmp.end(), num) != tmp.end()) {
            std::cerr << "Error" << std::endl;
            return 1;
        }

        tmp.push_back(num);
    }
    return 0;
}

/*
====== STORE INPUT =======
*/

void	storeInputVec(int argc, char **argv, std::vector<int>& vec)
{
	for (int i = 1; i < argc; i++)
		vec.push_back(std::atoi(argv[i]));
}

void	storeInputDeq(int argc, char **argv, std::deque<int>& deq)
{
	for (int i = 1; i < argc; i++)
		deq.push_back(std::atoi(argv[i]));
}

/*
====== SORTING UTILS =======
*/

int	organizeChains(int index, int blockSize, int totalSize)
{
	int numFullBlocks = totalSize / blockSize;
	int leftoverStart = numFullBlocks * blockSize;
	int	blockNum = index / blockSize;  // which block does this element belong to

	// leftover -> not main chain
	if (index >= leftoverStart)
	{
		//std::cout << "Blocknum in organizeChains() leftover chain: " << blockNum << std::endl;
		return 2;
	}

	// First block (b1) always goes to main chain
	if (blockNum == 0)
	{
		//std::cout << "Blocknum in organizeChains() main chain: " << blockNum << std::endl;
		return 0;
	}
	
	// main chain: odd-numbered blocks (a-blocks)
	if (blockNum % 2 != 0)
	{
		//std::cout << "Blocknum in organizeChains() main chain: " << blockNum << std::endl;
		return 0;
	}

	//std::cout << "Blocknum in organizeChains() pending chain: " << blockNum << std::endl;
	return 1;	// pending: all remaning b blocks (b2, b3, etc)
}
