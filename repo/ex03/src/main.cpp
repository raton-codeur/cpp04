#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		std::cout << "--- 1 ---" << std::endl;
		Cure cure;
		Ice ice;
		std::cout << "--- 2 ---" << std::endl;
		std::cout << cure.getType() << std::endl;
		std::cout << ice.getType() << std::endl;
		std::cout << "--- 3 ---" << std::endl;
		AMateria* cure2;
		cure2 = cure.clone();
		delete cure2;
		std::cout << "--- 4 ---" << std::endl;
		Character bob("bob");
		cure.use(bob);
		ice.use(bob);
		std::cout << "--- 5 ---" << std::endl;
		bob.equip(cure.clone());
		bob.equip(ice.clone());
		std::cout << "--- 6 ---" << std::endl;
		bob.use(0, bob);
		bob.use(1, bob);
		bob.use(2, bob);
		bob.unequip(0);
		bob.use(0, bob);
	}
}
