#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &Original);
		WrongCat &operator=(const WrongCat &Original);
		~WrongCat();
};

#endif