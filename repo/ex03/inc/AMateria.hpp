#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP
#include <iostream>
#include <string>
#include "ICharacter.hpp"
class ICharacter;

class AMateria
{
	protected :
		std::string _type;
	public :
							AMateria();
							AMateria(const AMateria& materia);
							AMateria(const std::string& type);
		AMateria&			operator=(const AMateria& materia);
		virtual				~AMateria();
		const std::string&	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif