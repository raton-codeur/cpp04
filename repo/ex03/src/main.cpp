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
		AMateria* cure2 = cure.clone();
		delete cure2;
		std::cout << "--- 4 ---" << std::endl;
		{
			Character c1;
			Character c2("bob");
			Character c3(c2);
			Character c4;
			c4 = c3;
		}
		std::cout << "--- 5 ---" << std::endl;
		Character bob("bob");
		cure.use(bob);
		ice.use(bob);

		AMateria *materials[2];
		std::cout << "--- 6 ---" << std::endl;
		materials[0] = cure.clone();
		materials[1] = ice.clone();
		std::cout << "--- 7 ---" << std::endl;
		bob.equip(materials[0]);
		bob.equip(materials[1]);
		bob.use(0, bob);
		bob.use(1, bob);
		bob.use(2, bob);
		bob.unequip(0);
		bob.use(0, bob);

		delete materials[0];
	}
}
