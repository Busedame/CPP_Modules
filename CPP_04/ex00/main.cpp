#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
	// Demonstrating how cat derives from animal.
	const Animal* animal = new Animal();
	const Cat* cat = new Cat();

	animal->makeSound();
	cat->makeSound();
	delete animal;
	animal = cat;
	animal->makeSound();
	delete cat;

	// Demonstrating all animals -> change to Wrong-classes for testing.
	const Animal* meta = new Animal();
	const Animal* cat2 = new Cat();
	const Animal* dog = new Dog();
	std::cout << cat2->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	meta->makeSound(); //will output the animal sound!
	cat2->makeSound(); //will output the cat sound!
	dog->makeSound(); //will output the dog sound!
	delete meta;
	delete cat2;
	delete dog;
	return (0);
}
