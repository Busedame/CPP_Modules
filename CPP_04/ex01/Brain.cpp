#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "I'm hungry";
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &Original)
{
	*this = Original;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &Original)
{
	if (this != &Original)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = Original.ideas[i];
	}
	std::cout << "Brain copy assignment operator called." << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
