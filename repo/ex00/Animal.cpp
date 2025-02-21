#include "Animal.hpp"

Animal::Animal() : _type("default animal")
{
	std::cout << "Animal : default constructor" << std::endl;
}

Animal::Animal(const Animal& animal) : _type(animal._type)
{
	std::cout << "Animal : copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
	_type = animal._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal : destructor" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "default sound" << std::endl;
}

const std::string& Animal::getType() const
{
	return _type;
}
