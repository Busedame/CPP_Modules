#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &Original);
		Cat &operator=(const Cat &Original);
		~Cat();
		void	getIdeas(void);
		void	setIdea(int Nbr, std::string newIdea);
	protected:
		std::string type;
	private:
		Brain*	brain;
};

#endif