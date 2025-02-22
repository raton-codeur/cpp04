#include "AMateria.hpp"

AMateria::AMateria() : _type("default type")
{
	std::cout << "AMateria : default constructor" << std::endl;
}

AMateria::AMateria(const AMateria& materia) : _type(materia._type)
{
	std::cout << "AMateria : copy constructor" << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type)
{
	std::cout << "AMateria : constructor" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& materia)
{
	_type = materia._type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria : destructor" << std::endl;
}

const std::string& AMateria::getType() const
{
	return _type;
}
