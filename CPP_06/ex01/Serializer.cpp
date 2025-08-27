#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constructor called!" << std::endl;
}

Serializer::Serializer(const Serializer& oth)
{
	(void)oth;
	std::cout << "Serializer copy constructor called!" << std::endl;
}
Serializer&	Serializer::operator=(const Serializer& oth)
{
	(void)oth;
	std::cout << "Serializer copy assignment called!" << std::endl;
	return *this;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called!" << std::endl;
}

// "reinterpret_cast" guarantees that if you cast a pointer to a different type, 
// and then reinterpret_cast it back to the original type, you get the original value.

// In this context:
// "Serialization" = encode a pointer as an integer.
// "Deserialization" = turn that integer back into the same pointer.

// Serialization turns the object into a portable, storable format. E.g. with a computer game to store the current state of the player for later (human readable, outside RAM).
// In this project - not really relevant. Just an introduction to <reinterpret_cast> as opposed to <static_cast> for pointers, discovering uintptr_t and conversion of pointer addresses.

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr->getPtr())); 
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
