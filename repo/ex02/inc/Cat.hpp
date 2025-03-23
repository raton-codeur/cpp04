#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private :
		Brain* _brain;
	public :
				Cat();
				Cat(const Cat& cat);
		Cat&	operator=(const Cat& cat);
				~Cat();
		void	makeSound() const;
};

#endif