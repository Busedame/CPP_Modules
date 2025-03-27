#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	Animal* j = new Dog();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
}
