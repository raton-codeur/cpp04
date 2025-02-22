#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
	std::cout << "Dog : default constructor" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& dog) : Animal(dog), _brain(new Brain(*dog._brain))
{
	std::cout << "Dog : copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
	Animal::operator=(dog);
	*_brain = *dog._brain;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog : destructor" << std::endl;
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "woof" << std::endl;
}
