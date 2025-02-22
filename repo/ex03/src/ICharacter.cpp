#include "ICharacter.hpp"

ICharacter::ICharacter() : _name("default name")
{
	std::cout << "ICharacter : default constructor" << std::endl;
}

ICharacter::ICharacter(const ICharacter& character) : _name(character._name)
{
	std::cout << "ICharacter : copy constructor" << std::endl;
}

ICharacter::ICharacter(const std::string& name) : _name(name)
{
	std::cout << "ICharacter : constructor" << std::endl;
}

ICharacter& ICharacter::operator=(const ICharacter& character)
{
	_name = character._name;
	return *this;
}

ICharacter::~ICharacter()
{
	std::cout << "ICharacter : destructor" << std::endl;
}
