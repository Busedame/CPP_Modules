#include "Serializer.hpp"

int	main()
{
	const char* str = "Hello, world!";
	const void*	ptr;

	ptr = str;
	std::cout << ptr << std::endl;


	Data	data;

	std::cout << "Data str: " << data.getStr() << std::endl;
	std::cout << "Data ptr: " << data.getPtr() << std::endl;

	uintptr_t	intPtr;

	intPtr = Serializer::serialize(&data);
	std::cout << "Data ptr after serializing: " << intPtr << std::endl;
	std::cout << "Data ptr after deserializing: " << Serializer::deserialize(intPtr) << std::endl;

}
