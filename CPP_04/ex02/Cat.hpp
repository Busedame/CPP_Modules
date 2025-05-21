#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal, public Brain
{
	public:
		Cat();
		Cat(const Cat &Original);
		Cat &operator=(const Cat &Original);
		virtual ~Cat();
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