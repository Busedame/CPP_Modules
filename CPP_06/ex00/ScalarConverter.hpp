#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <climits>
# include <limits>
# include <cfloat>
# include <cmath>

struct Parser
{
	int	i;
	float	f;
	double	d;
	char	c;
	bool	isFloat;
	bool	isInt;
	bool	isDouble;
	bool	isChar;
	bool	intImpossible;
	bool	charImpossible;
	bool	charNonDisplayable;
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& oth);
		ScalarConverter&	operator=(const ScalarConverter& oth);
		~ScalarConverter();

		static int	handlePseudoLiterals(std::string str, Parser &p);

		static int	nonDisplayable(std::string str);

		static int	checkType(std::string str, Parser& p);
		static void checkInt(std::string str, Parser &p);
		static void checkFloat(std::string str, Parser &p);
		static void	checkChar(std::string str, Parser& p);
		static void	checkDouble(std::string str, Parser& p);

		static void	doConversion(std::string str, Parser& p);
		static void	convertChar(std::string str, Parser& p);
		static void	convertInt(std::string str, Parser& p);
		static void	convertFloat(std::string str, Parser& p);
		static void	convertDouble(std::string str, Parser& p);

		static void	printTypes(Parser &p);
	public:
		static int	convert(std::string str);
};

#endif
