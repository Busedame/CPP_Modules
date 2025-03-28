#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	// const Animal* meta = new Animal();
	// const Animal* cat = new Cat();
	// const Animal* dog = new Dog();
	// std::cout << cat->getType() << " " << std::endl;
	// std::cout << dog->getType() << " " << std::endl;
	// meta->makeSound();
	// cat->makeSound(); //will output the cat sound!
	// dog->makeSound(); //will output the dog sound!
	// cat->getIdeas();
	// delete meta;
	// delete cat;
	// delete dog;

	Cat	test;
	test.makeSound();
	test.setIdea(0, "Maybe I can break this...");
	test.setIdea(1, "I like fish...");
	test.getIdeas();
	return (0);
}
