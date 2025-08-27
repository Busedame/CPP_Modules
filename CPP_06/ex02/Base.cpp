#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base * generate(void)
{
	srand(time(NULL));
	int nbr = rand() % 6;

	if (nbr == 0 || nbr == 1)
		return new A;
	else if (nbr == 2 || nbr == 3)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type is C" << std::endl;
	else
		std::cerr << "Invalid pointer" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type is A" << std::endl;
		return ;
	}
	catch(const std::exception& e){}

	try 
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type is B" << std::endl;
		return ;
	}
	catch(const std::exception& e){}

	try 
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type is C" << std::endl;
		return ;
	}
	catch(const std::exception& e){}

	std::cerr << "Invalid reference" << std::endl;
}
