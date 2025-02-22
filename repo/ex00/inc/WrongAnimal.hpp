#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP
#include <iostream>
#include <string>

class WrongAnimal
{
	protected :
		std::string _type;
	public :
							WrongAnimal();
							WrongAnimal(const WrongAnimal& wrongAnimal);
		WrongAnimal&		operator=(const WrongAnimal& wrongAnimal);
		virtual				~WrongAnimal();
		const std::string&	getType() const;
		void				makeSound() const;
};

#endif