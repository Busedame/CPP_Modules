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

Zombie* zombieHorde(int N, std::string name);

#endif