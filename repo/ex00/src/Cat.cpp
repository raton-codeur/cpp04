#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat : default constructor" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	std::cout << "Cat : copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
	Animal::operator=(cat);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat : destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}
