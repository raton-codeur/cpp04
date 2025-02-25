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
		std::cout << "--- 6 ---" << std::endl;
		AMateria *materials[6];
		for (int i = 0; i < 3; i++)
		materials[i] = ice.clone();
		for (int i = 3; i < 6; i++)
		materials[i] = cure.clone();
		std::cout << "--- 7 ----" << std::endl;
		bob.equip(materials[3]); // cure
		bob.equip(materials[0]); // ice
		bob.equip(materials[1]); // ice
		bob.equip(materials[4]); // cure
		bob.equip(materials[5]); // cure 5 not equiped → to be freed manually
		bob.use(0, bob);
		bob.use(1, bob);
		bob.use(2, bob);
		bob.use(3, bob);
		bob.unequip(0); // cure 3 dropped → to be freed manually
		bob.use(0, bob); // N/A
		bob.equip(materials[2]); // ice
		bob.use(0, bob);
		delete materials[3];
		delete materials[5];
		std::cout << "--- 8 ----" << std::endl;
		Character bob2(bob);
		std::cout << "--- 9 ----" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		std::cout << "--- 10 ----" << std::endl;
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("cure"));
		me->use(0, bob);
		me->use(1, bob);
		delete me;
		std::cout << "--- 12 ----" << std::endl;
		delete src;
		std::cout << "--- 11 ----" << std::endl;
	}
}
