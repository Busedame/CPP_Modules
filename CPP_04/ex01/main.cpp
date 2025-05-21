#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	// // Creates an array of animals - half is cats and half is dogs.
	// const Animal* animals[10];
	// for (int i = 0; i < 5; i++)
	// 	animals[i] = new Cat();
	// for (int i = 5; i < 10; i++)
	// 	animals[i] = new Dog();
	// for (int i = 0; i < 10; i++)
	// 	animals[i]->makeSound();
	// for (int i = 0; i < 10; i++)
	// 	delete animals[i];

	// // Checking that copy assignment and copy constructor work as expected.
	// Dog *dog = new Dog();
	// dog->setIdea(0, "I like ice cream");
	// // Dog dog2(*dog);
	// Dog dog2;
	// dog2 = *dog;
	// dog2.printIdeas();
	// std::cout << dog2.getType() << std::endl;	
	// delete dog;

	// Checking to see if assignment_dog is a deep copy of dog.
	Dog dog;
	Dog assignment_dog(dog);
	std::cout << std::endl;
	
	std::cout << "This is idea 10 from dog: " << dog.getIdea(10) << std::endl;
	dog.setIdea(10, "This is the new idea to paint the moon");
	std::cout << "This is the new idea 10 from dog: " << dog.getIdea(10) << std::endl;
	std::cout << std::endl;

	std::cout << "This is idea 10 from assignment_dog before assignment: " << assignment_dog.getIdea(10) << std::endl;
	assignment_dog = dog;
	std::cout << "This is idea 10 from assignment_dog after assignment: " << assignment_dog.getIdea(10) << std::endl;
	std::cout << std::endl;

	assignment_dog.setIdea(10, "Better paint the mars!");
	std::cout << "This is the new idea 10 from assignment dog: " << assignment_dog.getIdea(10) << std::endl;
	std::cout << "This is idea 10 from dog: " << dog.getIdea(10) << std::endl;

	std::cout << std::endl;
}
