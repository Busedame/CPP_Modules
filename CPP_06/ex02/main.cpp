#include "Base.hpp"

int	main()
{
	Base	*p = generate();
	std::cout << "Pointer identify: ";
	identify(p);
	std::cout << "Reference identify: ";
	identify(*p);

	delete p;

	Base b;
	std::cout << "Pointer identify: ";
	identify(&b);
	// identify(NULL);
	std::cout << "Reference identify: ";
	identify(b);
}
