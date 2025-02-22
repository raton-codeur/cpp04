#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource : default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
	std::cout << "MateriaSource : copy constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = 0;
	*this = materiaSource;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i])
			delete _materia[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (materiaSource._materia[i])
			_materia[i] = materiaSource._materia[i]->clone();
		else
			_materia[i] = 0;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource : destructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i])
			delete _materia[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] == 0)
		{
			_materia[i] = materia;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] && _materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return 0;
}
