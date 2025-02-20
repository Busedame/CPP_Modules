#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
# include <iostream>
# include <cctype>
# include <cstring>
# include <string>
# include <iomanip>

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie();
		void	announce( void );
	private:
		std::string name;
};

// The two following functions are outside of the class:
	Zombie	*newZombie( std::string name );
	void	randomChump( std::string name );

#endif