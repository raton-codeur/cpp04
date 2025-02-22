#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain : default constructor" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "default idea";
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain : copy constructor" << std::endl;
	*this = brain;
}

Brain& Brain::operator=(const Brain& brain)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = brain._ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain : destructor" << std::endl;
}
