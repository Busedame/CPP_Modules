#include "PmergeMeVec.hpp"
#include "PmergeMeDeq.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	// Parse input
	if (parseInput(argc, argv))
		return 1;

	// ====== Sort vector =======
	PmergeMeVec sortVec;
	std::vector<int> vec;
	int numCmpVec = 0;
	clock_t start_vec = clock();							   // Start time for vec
	sortVec.mergeInsertSortVector(argc, argv, numCmpVec, vec); // Actual sorting for vec
	clock_t end_vec = clock();								   // End time for vec

	// ====== Sort deque =======
	PmergeMeDeq sortDeq;
	std::deque<int> deq;
	int numCmpDeq = 0;
	clock_t start_deq = clock();							  // Start time for deq
	sortDeq.mergeInsertSortDeque(argc, argv, numCmpDeq, deq); // Actual sorting for deq
	clock_t end_deq = clock();								  // End time for deq

	// ====== Print before and after =======
	printUnsorted(argc, argv);
	printVec(vec);
	// printDeq(deq);

	// ====== Calculate and print "time to process" =======
	double duration_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6;
	double duration_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1e6;
	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector : " << duration_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
			  << " elements with std::deque : " << duration_deq << " us" << std::endl;

	// THIS ONLY WORKS WITHOUT C++ 1998 (checks if it is actually sorted).
	// bool sorted = std::is_sorted(vec.begin(), vec.end());
	// std::cout << "Is sorted?: " << sorted << std::endl;

	std::cout << "Max comparisons allowed for " << vec.size() << " numbers: " << maxComparisonsFJ(vec.size()) << std::endl;
	std::cout << "Amount of comparisons made in vector: " << numCmpVec << std::endl;
	std::cout << "Amount of comparisons made in deque: " << numCmpDeq << std::endl;

	return 0;
}
