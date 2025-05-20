#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	const Animal* animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Cat();
	for (int i = 5; i < 10; i++)
		animals[i] = new Dog();
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete animals[i];

	Cat cat;
	cat.setIdea(0, "I like ice cream");
	Cat cat2 = cat;
	cat2.getIdeas();
}
