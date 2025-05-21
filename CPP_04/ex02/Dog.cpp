#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &Original) : Animal(Original.type)
{
	brain = new Brain(*Original.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &Original)
{
	if (this != &Original)
	{
		type = Original.type;
		for (int i = 0; i < 100; i++)
			setIdea(i, Original.ideas[i]);
	}
	std::cout << "Dog copy assignment operator called." << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "bark bark" << std::endl;
}

void	Dog::printIdeas(void)
{
	for (int i = 0; i < 100; i++)
		std::cout << "Idea " << i + 1 << ": '" << ideas[i] << "'" << std::endl;
}

std::string	Dog::getIdea(int i)
{
	return (ideas[i]);
}

void	Dog::setIdea(int Nbr, std::string newIdea)
{
	if (Nbr >= 0 && Nbr < 100)
		ideas[Nbr] = newIdea;
	else
		std::cout << "Idea number must be between 0 and 99." << std::endl;
}
