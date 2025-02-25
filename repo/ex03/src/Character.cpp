#include "Character.hpp"
#include <cstring>

Character::Character() : _name("default name")
{
	std::cout << "Character : default constructor" << std::endl;
	std::memset(_inventory, 0, sizeof(_inventory));
}

Character::Character(const std::string& name) : _name(name)
{
	std::cout << "Character " << _name << " : constructor" << std::endl;
	std::memset(_inventory, 0, sizeof(_inventory));
}

Character::Character(const Character& character) : _name(character._name)
{
	std::cout << "Character " << _name << " : copy constructor" << std::endl;
	std::memset(_inventory, 0, sizeof(_inventory));
	*this = character;
}

Character& Character::operator=(const Character& character)
{
	if (this == &character)
		return *this;
	_name = character._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (character._inventory[i])
			_inventory[i] = character._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character " << _name << " : destructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

const std::string& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == 0)
		{
			_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int i)
{
	if (i < 0 || i >= 4)
		return;
	_inventory[i] = 0;
}

void Character::use(int i, ICharacter& target)
{
	if (i < 0 || i >= 4 || _inventory[i] == 0)
		return;
	_inventory[i]->use(target);
}
