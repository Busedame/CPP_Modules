#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	// Creates an array of animals - half is cats and half is dogs.
	const Animal* animals[10]; // This works because pointers can point to objects of any class derived from Animal, such as Cat or Dog.
	// This is because the constructors of Animal-class are protected and can be accessed by the derived classes.
	for (int i = 0; i < 5; i++)
		animals[i] = new Cat();
	for (int i = 5; i < 10; i++)
		animals[i] = new Dog();
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete animals[i];

	// Animal	animal; // Does not work.
}
