#include "MateriaSource.hpp"
#include <cstring>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource : default constructor" << std::endl;
	std::memset(_materials, 0, sizeof(_materials));
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
	std::cout << "MateriaSource : copy constructor" << std::endl;
	std::memset(_materials, 0, sizeof(_materials));
	*this = materiaSource;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource)
{
	if (this == &materiaSource)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		if (_materials[i])
			delete _materials[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (materiaSource._materials[i])
			_materials[i] = materiaSource._materials[i]->clone();
		else
			_materials[i] = 0;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource : destructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_materials[i])
			delete _materials[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materials[i] == 0)
		{
			_materials[i] = materia;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materials[i] && _materials[i]->getType() == type)
			return _materials[i]->clone();
	}
	return 0;
}
