#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default wrong animal")
{
	std::cout << "WrongAnimal : default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal) : _type(animal._type)
{
	std::cout << "WrongAnimal : copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& animal)
{
	_type = animal._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal : destructor" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "default sound" << std::endl;
}
