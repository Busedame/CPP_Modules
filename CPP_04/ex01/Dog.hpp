#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &Original);
		Dog &operator=(const Dog &Original);
		~Dog();
		void	getIdeas(void);
		void	setIdea(int Nbr, std::string newIdea);
	protected:
		std::string type;
	private:
		Brain*	brain;
};

#endif