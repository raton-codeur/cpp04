#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private :
		std::string	_name;
		AMateria*	_inventory[4];
	public :
							Character();
							Character(const std::string& name);
							Character(const Character& character);
		Character&			operator=(const Character& character);
							~Character();
		const std::string&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int i);
		void				use(int i, ICharacter& target);
};

#endif