#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &Original);
		Brain &operator=(const Brain &Original);
		~Brain();
		std::string	ideas[100];
};

#endif