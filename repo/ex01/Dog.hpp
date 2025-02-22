#ifndef DOG_H
#define DOG_H
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private :
		Brain* _brain;
	public :
				Dog();
				Dog(const Dog& dog);
		Dog&	operator=(const Dog& dog);
				~Dog();
		void	makeSound() const;
};

#endif