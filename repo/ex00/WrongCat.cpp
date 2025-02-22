#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat : default constructor" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& wrongCat) : WrongAnimal()
{
	std::cout << "WrongCat : copy constructor" << std::endl;
	_type = wrongCat._type;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
	WrongAnimal::operator=(wrongCat);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat : destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "meow" << std::endl;
}
