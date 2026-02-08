#include "BitcoinExchange.hpp"

/*
====== CONSTRUCTORS AND DESTRUCTOR =======
*/

BitcoinExchange::BitcoinExchange(): csvData(), line() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& oth) : csvData(oth.csvData), line(oth.line) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& oth) {
	if (this != &oth) {
		csvData = oth.csvData;
		line = oth.line;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}


/*
====== PARSE INPUT =======
*/

// Checks if the date is a valid date (leap year, correct day considering month).
int	BitcoinExchange::validateDate(std::vector<std::string>& date, std::string& file, int lineIndex)
{
	unsigned int year = static_cast<unsigned int>(atol(date[0].c_str()));
	unsigned int month = static_cast<unsigned int>(atol(date[1].c_str()));
	unsigned int day = static_cast<unsigned int>(atol(date[2].c_str()));

	if (month < 1 || month > 12) {
		std::cerr << "Error: " << file << " => bad input in line " << lineIndex << ": '" << line << "' Month must be between 1 and 12." << std::endl;
		return 1;
	}

	if (day < 1) {
		std::cerr << "Error: " << file << " => bad input in line " << lineIndex << ": '" << line << "' Day must be > 0." << std::endl;
		return 1;
	}

	unsigned int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
	bool isLeap =
        (year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0);

    if (isLeap) {
        daysInMonth[1] = 29;
	}

	for (unsigned int i = 0; i < 12; i++) {
		if (i == month - 1 && day > daysInMonth[i]) {
			std::cerr << "Error: " << file << " => bad input in line " << lineIndex << ": '" << line << "' Day does not exist in month " << month << " in year " << year << std::endl;
			return 1;
		}
	}

	return 0;
}

// Check if the date format is correct (YYYY-MM-DD) with no non-numerical characters.
int	BitcoinExchange::checkDate(std::vector<std::string>& date, std::string& file, int lineIndex)
{
	int	i = 0;
	int ivec = 0;
	
	while (ivec < 3) {
		i = 0;
		while (date[ivec][i] != '\0' && isdigit(date[ivec][i]))
			i++;
		if (date[ivec][i] != '\0') {
			std::cerr << "Error: " << file << " => bad input in line " << lineIndex << ": '" << line << "' Date contains non-numerical characters." << std::endl;
			return 1;
		}
		ivec++;
	}

	if (validateDate(date, file, lineIndex))
		return 1;

	return 0;
}

// Validate the value format, and checking if it's within correct range.
int	BitcoinExchange::checkValue(std::string& valueStr, std::string& file, int lineIndex)
{
	int		i = 0;
	bool	dotFound = false;
	bool	digitFound = false;

	// If first character is anything else than '.'
	if (!isdigit(valueStr[i]) && valueStr[i] != '.') {
		std::cerr << "Error: " << file << " => bad input in line " << lineIndex << ": '" << line << "' Value must be numeric value and can't be < 0." << std::endl;
		return 1;
	}

	// If first character is '.'
	if (valueStr[i] == '.') {
		dotFound = true;
		i++;
	}

	while (valueStr[i] != '\0')
	{
		if (valueStr[i] == '.') {
			if (!dotFound) {
				dotFound = true;
				i++;
				continue ;
			}
			else {
				std::cerr << "Error: " << file << " => bad input in line " << lineIndex << ": '" << line << "' Value wrongly formatted. Several dots found." << std::endl;
				return 1;
			}
		}
		else if (!isdigit(valueStr[i])) {
			std::cerr << "Error: " << file << " => bad input in line " << lineIndex << ": '" << line << "' Value wrongly formatted. Non-numerical characters found." << std::endl;
			return 1;
		}
		if (!digitFound)
			digitFound = true;
		i++;
	}

	if (!digitFound) {
		std::cerr << "Error: " << file << " => bad input in line " << lineIndex << ": '" << line << "' Value contains no digits." << std::endl;
		return 1;
	}

	// Converting value to see if it is bigger than 1000 (not allowed in input file).
	double value = atof(valueStr.c_str());
	if (value < 0) {
		std::cerr << "Error: " << file << " => bad input in line " << lineIndex << ": '" << line << "' Value can't be < 0." << std::endl;
		return 1;
	}

	if (file != "CSV file" && value > 1000) {
		std::cerr << "Error: " << file << " => bad input in line " << lineIndex << ": '" << line << "' Value can't be > 1000." << std::endl;
		return 1;
	}

	return 0;
}

// Validates the line (date and value is correct?).
int	BitcoinExchange::checkAndSetLine(std::string& dateStr, std::string& valueStr, int lineIndex, std::string& file) {
	std::vector<std::string> date = split(dateStr, '-');

	if (date.size() != 3) {
		std::cerr << "Error: " << file << " => bad input in line " << lineIndex << ": '" << line << "' Invalid date format." << std::endl;
		return 1;
	}
	if (date[0].length() != 4 || date[1].length() != 2 || date[2].length() != 2) {
		std::cerr << "Error: " << file << " => bad input in line " << lineIndex << ": '" << line << "' Invalid date format." << std::endl;
		return 1;
	}
	if (checkDate(date, file, lineIndex))
		return 1;
	if (checkValue(valueStr, file, lineIndex))
		return 1;
	return 0;
}


/*
====== MAIN PARSING FUNCTION =======
*/

std::vector<std::string> BitcoinExchange::parseFile(int lineIndex, char delimiter, bool csv) {

	// Setting right file for error message
	std::string	file;
	if (csv)
		file = "CSV file";
	else
		file = "Input file";

	// Check if the expected '|' or ',' is in the line.
	std::vector<std::string> tokens = split(line, delimiter);
	if (tokens.size() != 2) {
			std::cerr << "Error: " << file << " => bad input in line " << lineIndex << ": " << line << ". Expected format: <YYYY-MM-DD | value>." << std::endl;
		return std::vector<std::string>();
	}

	// Check if date and value are correctly formatted.
	if (checkAndSetLine(tokens[0], tokens[1], lineIndex, file))
		return std::vector<std::string>();
	return tokens;
}

/*
====== MAIN CLASS FUNCTION =======
*/

void	BitcoinExchange::run(std::ifstream& fileFd,std::ifstream& csvFileFd)
{
	int 	i = 0;
	bool	firstLine = true;

	// Parsing and storing csv file
	while (std::getline(csvFileFd, line)) {
		i++;
		if (line.empty())
			continue;
		if (firstLine) {
			if (line != "date,exchange_rate") {
				std::cerr << "Error in CSV-file: header missing or wrong header format. Exiting program..." << std::endl;
				return ;
			}
			firstLine = false;
			continue;
		}

		std::vector<std::string> tokens = parseFile(i, ',', true);
		if (tokens.empty())
			continue;
		setCsvData(tokens[0], atof(tokens[1].c_str()));
	}

	line = "";
	i = 0;

	// Parsing and storing input file
	while (std::getline(fileFd, line)) {
		i++;
		if (line.empty())
			continue;

		std::vector<std::string> tokens = parseFile(i, '|', false);
		if (tokens.empty())
			continue;
		exchange(tokens[0], atof(tokens[1].c_str()), i);
	}
}

/*
====== EXCHANGE =======
*/

// Takes a line from input file, finds the matching or closest earlier date in CSV file -> multiplies the input amount with rate for BTC for that date.
void	BitcoinExchange::exchange(std::string& date, double value, int lineIndex)
{

	// Finds the first CSV date that is >= the input date (or end() if none exists).
	std::map<std::string, double>::const_iterator csvIt = csvData.lower_bound(date);

	// This would mean that input date is greater than anything stored in CSV file, so go one back
	if (csvIt == csvData.end()) { 
			--csvIt;
	}

	// 1. If input date does not match exactly
	else if (csvIt->first != date) {
		
		// (If input date is earlier than anything stored in CSV file, then no earlier date is available.)
		if (csvIt == csvData.begin()) {
			std::cerr << "Error: " << "Input file" << " => bad input in line " << lineIndex << ": " << line << ". No identical or earlier date entry found in CSV file." << std::endl;
			return ;
		}
		
		// 2. Go back one, to find the closest earlier entry.
		--csvIt;
	}

	// Print out either the value on the exact date, or the closest earlier date.
	std::cout << date << " => "
		<< value << " = "
		<< value * csvIt->second
		<< std::endl;
}

/*
====== UTILS =======
*/

void	BitcoinExchange::printMap(void) {
	for (std::map<std::string, double>::const_iterator it = csvData.begin(); it != csvData.end(); it++) {
    		std::cout << it->first << ", " << it->second << std::endl;
	}
}

void	BitcoinExchange::setCsvData(std::string date, double value) {
	csvData.insert(std::make_pair(date, value));
}

/*
====== OUTSIDE CLASS UTILS =======
*/

std::string	trim(const std::string& str)
{
	size_t start = 0;
	size_t end = str.length();

	while (start < end && std::isspace(static_cast<unsigned char>(str[start])))
		start++;
	while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
		end--;

	return str.substr(start, end - start);
}

std::vector<std::string> split(const std::string& str, char delimiter)
{
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string item;

	while (std::getline(ss, item, delimiter)) {

		// Add item to tokens
		tokens.push_back(trim(item));
	}

	return tokens;
}
