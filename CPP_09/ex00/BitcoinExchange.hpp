#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <string>
# include <algorithm>
# include <cctype>
# include <map>
# include <cstdlib>


class BitcoinExchange
{
	private:
		std::map<std::string, double> csvData;
		std::string 	line;

		// Exchange
		void	exchange(std::string& date, double value, int lineIndex);

		// Parsing utils
		int	validateDate(std::vector<std::string>& date, std::string& file, int lineIndex);
		int	checkDate(std::vector<std::string>& date, std::string& file, int lineIndex);
		int	checkValue(std::string& valueStr, std::string& file, int lineIndex);
		int	checkAndSetLine(std::string& dateStr, std::string& valueStr, int lineIndex, std::string& file);

		// Main parsing function
		std::vector<std::string> parseFile(int i, char delimiter, bool csv);

		// Utils
		void	printMap(void);
		void	setCsvData(std::string date, double value);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& oth);
		BitcoinExchange&	operator=(const BitcoinExchange& oth);
		~BitcoinExchange();

		// Main class function
		void	run(std::ifstream& fileFd, std::ifstream& csvFileFd);
};

// Outside class utils
std::string	trim(const std::string& str);
std::vector<std::string> split(const std::string& str, char delimiter);

#endif