#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private :
		AMateria* _materials[4];
	public :
						MateriaSource();
						MateriaSource(const MateriaSource& materiaSource);
		MateriaSource&	operator=(const MateriaSource& materiaSource);
						~MateriaSource();
		void			learnMateria(AMateria*);
		AMateria*		createMateria(const std::string& type);
};

#endif