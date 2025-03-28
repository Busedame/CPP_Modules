#include "Dog.hpp"

Dog::Dog() : Animal()
{
	setType("Dog");
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &Original)
{
	*this = Original;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &Original)
{
	if (this != &Original)
		type = Original.type;
	std::cout << "Dog copy assignment operator called." << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::getIdeas(void)
{
	for (int i = 0; i < 100; i++)
		std::cout << "Idea " << i + 1 << ": '" << brain->ideas[i] << "'" << std::endl;
}

void	Dog::setIdea(int Nbr, std::string newIdea)
{
	if (Nbr >= 0 && Nbr < 100)
		brain->ideas[Nbr] = newIdea;
	else
		std::cout << "Idea number must be between 0 and 99." << std::endl;
}
