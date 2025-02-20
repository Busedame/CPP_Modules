#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* array = new Zombie[N]; // Allocate memory for an array of zombies -> N zombies are getting allocated.
	for (int i = 0; i < N; i++)
		new (&array[i]) Zombie(name); // This line is referring to &array[i] -> where memory has already been allocated. It's basically just a memory address, where
		// memory has already been allocated.
		// It then says to CONSTRUCT a zombie(name) there, but not to allocate memory, as that has already been done.
		//array[i] = Zombie(name); // This line is accidentally allocating each individual zombie again. Array[i] is already an allocated Zombie instance, so this is wrong.
	return (array);
}
