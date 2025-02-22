#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice : constructor" << std::endl;
}

Ice::Ice(const Ice& ice) : AMateria(ice)
{
	std::cout << "Ice : copy constructor" << std::endl;
}

Ice& Ice::operator=(const Ice& ice)
{
	AMateria::operator=(ice);
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice : destructor" << std::endl;
}
