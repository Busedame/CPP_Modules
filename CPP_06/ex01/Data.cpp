#include "Serializer.hpp"

Data::Data() : str("Hello, world!"), ptr(str)
{
	std::cout << "Data struct constructor called!" << std::endl;
}

Data::Data(const Data& oth) : str(oth.str), ptr(oth.ptr)
{
	std::cout << "Serializer copy constructor called!" << std::endl;
}

Data&	Data::operator=(const Data& oth)
{
	(void)oth;
	std::cout << "Serializer copy assignment called!" << std::endl;
	return *this;
}

Data::~Data()
{
	std::cout << "Data struct destructor called!" << std::endl;
}

const char	*Data::getStr(void)
{
	return str;
}
const void	*Data::getPtr(void)
{
	return ptr;
}

