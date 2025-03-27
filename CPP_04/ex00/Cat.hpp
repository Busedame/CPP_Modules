#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &Original);
		Cat &operator=(const Cat &Original);
		~Cat();
	private:
		std::string type;
};

#endif