#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor called!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& oth)
{
	(void)oth;
	std::cout << "ScalarConverter copy constructor called!" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& oth)
{
	(void)oth;
	std::cout << "ScalarConverter copy assignment called!" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called!" << std::endl;
}

void	ScalarConverter::printTypes(Parser &p)
{
	if (p.charImpossible)
		std::cout << "char: impossible" << std::endl;
	else if (p.charNonDisplayable)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << p.c << "'" << std::endl;

	if (p.intImpossible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << p.i << std::endl;

	float	dotCheck;

	if ((!std::modf(p.f, &dotCheck)) == 0.0 || std::isinf(p.d))
	{
		std::cout << "float: " << p.f << "f" << std::endl;
		std::cout << "double: " << p.d << std::endl;
	}
	else
	{
		std::cout << "float: " << p.f << ".0f" << std::endl;
		std::cout << "double: " << p.d << ".0" << std::endl;
	}
}

void	ScalarConverter::convertChar(std::string str, Parser& p)
{
	char c = str[1];
	p.i = static_cast<int>(c);
	p.f = static_cast<float>(c);
	p.d = static_cast<double>(c);
}

void	ScalarConverter::convertInt(std::string str, Parser& p)
{
	int	nbr = atoi(str.c_str());
	p.c = static_cast<char>(nbr);
	p.f = static_cast<float>(nbr);
	p.d = static_cast<double>(nbr);
}

void	ScalarConverter::convertFloat(std::string str, Parser& p)
{
	float nbr = static_cast<float>(atof(str.c_str()));
	p.c = static_cast<char>(nbr);
	p.i = static_cast<int>(nbr);
	p.d = static_cast<double>(nbr);
}

void	ScalarConverter::convertDouble(std::string str, Parser& p)
{
	double nbr = atof(str.c_str());
	p.c = static_cast<char>(nbr);
	p.i = static_cast<int>(nbr);
	p.f = static_cast<float>(nbr);
}

void	ScalarConverter::doConversion(std::string str, Parser& p)
{
	if (p.isChar)
		convertChar(str, p);
	else if (p.isInt)
		convertInt(str, p);
	else if (p.isFloat)
		convertFloat(str, p);
	else
		convertDouble(str, p);
}

void	ScalarConverter::checkChar(std::string str, Parser& p)
{
	if (str.length() == 3)
	{
		if (str[0] == '\'' && isprint(str[1]) && str[2] == '\'')
		{
			p.c = str[1];
			p.isChar = true;
			return ;
		}
	}
	long l = atol(str.c_str());
	if (l < 0 || l > 127)
		p.charImpossible = true;
	if (!isprint(static_cast<char>(l)))
		p.charNonDisplayable = true;
}

void	ScalarConverter::checkInt(std::string str, Parser& p)
{
	long l = atol(str.c_str());

	if (l < INT_MIN || l > INT_MAX)
	{
		p.intImpossible = true;
		return ;
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && str[i] == '-')
			continue ;
		if (!isdigit(str[i]))
			return ;
	}
	p.i = static_cast<int>(l);
	p.isInt = true;
}

void	ScalarConverter::checkFloat(std::string str, Parser& p)
{
	int	i = 0;
	if (str[i] == '-') // If there is a sign, skip it.
		i++;
	if (str[i] != '\0' && !isdigit(str[i])) // If the current character is not a digit, return.
		return ;
	while (str[i] != '\0' && isdigit(str[i])) // While there are only digits, increment.
		i++;
	if (str[i] == '\0' || (str[i] != '\0' && str[i++] != '.')) // If end is reached, or the current character is not '.', return.
		return ;
	if (str[i] == '\0' || (str[i] != '\0' && !isdigit(str[i]))) // If nothing after '.' or anything else than a number, return.
		return ;
	while (str[i] != '\0' && isdigit(str[i])) // While digits
		i++;
	if (str[i] != '\0' && str[i] == 'f' && str[i + 1] == '\0')
	{
		p.f = static_cast<float>(atof(str.c_str()));
		p.isFloat = true;
	}
}

void	ScalarConverter::checkDouble(std::string str, Parser& p)
{
	int	i = 0;
	if (str[i] == '-') // If there is a sign, skip it.
		i++;
	if (str[i] != '\0' && !isdigit(str[i])) // If the current character is not a digit, return.
		return ;
	while (str[i] != '\0' && isdigit(str[i])) // While there are only digits, increment.
		i++;
	if (str[i] == '\0' || (str[i] != '\0' && str[i++] != '.')) // If end is reached, or the current character is not '.', return.
		return ;
	if (str[i] == '\0' || (str[i] != '\0' && !isdigit(str[i]))) // If nothing after '.' or anything else than a number, return.
		return ;
	while (str[i] != '\0' && isdigit(str[i])) // While digits
		i++;
	if (str[i] == '\0' )
	{
		p.d = atof(str.c_str());
		p.isDouble = true;
	}
}

int	ScalarConverter::checkType(std::string str, Parser& p)
{
	checkFloat(str, p);
	checkInt(str, p);
	checkChar(str, p);
	checkDouble(str, p);
	if (!p.isChar && !p.isInt && !p.isFloat && !p.isDouble)
	{
		std::cerr << "Invalid input." << std::endl;
		return (1);
	}
	return (0);
}

int	ScalarConverter::handlePseudoLiterals(std::string str, Parser &p)
{
	if (str == "nan" || str == "nanf")
	{
		p.charImpossible = true;
		p.intImpossible = true;
		p.f = nanf("");
		p.d = nan("");
		return (1);
	}
	if (str == "-inff" || str == "-inf" || str == "inff" || str == "inf" || str == "+inff" || str == "+inf")
	{
		if (str == "-inff" || str == "-inf")
		{
			p.f = -std::numeric_limits<float>::infinity();
			p.d = -std::numeric_limits<double>::infinity();
		}
		else
		{
			p.f = std::numeric_limits<float>::infinity();
			p.d = std::numeric_limits<double>::infinity();
		}
		p.charImpossible = true;
		p.intImpossible = true;
		return (1);
	}
	return (0);
}

int	ScalarConverter::nonDisplayable(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isprint(str[i]))
		{
			std::cerr << "Non displayable input" << std::endl;
			return (1);
		}
	}
	return (0);
}

int	ScalarConverter::convert(std::string str)
{
	Parser	p = Parser();
	if (str.empty())
		return (1);
	if (nonDisplayable(str))
		return (1);
	if (!handlePseudoLiterals(str, p))
	{
		if (checkType(str, p))
			return (1);
		doConversion(str, p);
	}
	printTypes(p);
	return (0);
}
