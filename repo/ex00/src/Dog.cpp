#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog : default constructor" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	std::cout << "Dog : copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
	Animal::operator=(dog);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog : destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "woof" << std::endl;
}
