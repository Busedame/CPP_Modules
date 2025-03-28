#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	const Animal cat2(*cat); // Look into this
	const WrongAnimal* wcat = new WrongCat();
	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << wcat->getType() << " " << std::endl;
	meta->makeSound();
	cat->makeSound(); //will output the cat sound!
	dog->makeSound(); //will output the dog sound!
	wcat->makeSound(); //will output the wrong cat sound!
	delete meta;
	delete cat;
	delete dog;
	delete wcat;
	return (0);
}
