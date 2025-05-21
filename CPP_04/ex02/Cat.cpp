#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &Original) : Animal(Original.type)
{
	brain = new Brain(*Original.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &Original)
{
	if (this != &Original)
	{
		type = Original.type;
		for (int i = 0; i < 100; i++)
			setIdea(i, Original.ideas[i]);
	}
	std::cout << "Cat copy assignment operator called." << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "meow meow" << std::endl;
}

void	Cat::printIdeas(void)
{
	for (int i = 0; i < 100; i++)
		std::cout << "Idea " << i + 1 << ": '" << ideas[i] << "'" << std::endl;
}

std::string	Cat::getIdea(int i)
{
	return (ideas[i]);
}

void	Cat::setIdea(int Nbr, std::string newIdea)
{
	if (Nbr >= 0 && Nbr < 100)
		ideas[Nbr] = newIdea;
	else
		std::cout << "Idea number must be between 0 and 99." << std::endl;
}
