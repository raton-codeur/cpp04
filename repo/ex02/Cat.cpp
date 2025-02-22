#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
	std::cout << "Cat : default constructor" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& cat) : Animal(cat), _brain(new Brain(*cat._brain))
{
	std::cout << "Cat : copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
	Animal::operator=(cat);
	*_brain = *cat._brain;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat : destructor" << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}
