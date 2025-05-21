#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal, public Brain
{
	public:
		Dog();
		Dog(const Dog &Original);
		Dog &operator=(const Dog &Original);
		virtual ~Dog();
		virtual void	makeSound(void) const;
		void	printIdeas(void);
		std::string	getIdea(int i);
		void	setIdea(int Nbr, std::string newIdea);
	protected:
		std::string type;
	private:
		Brain*	brain;
};

#endif