#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "--- 1 ---" << std::endl;
	{
		Animal animal;
		std::cout << animal.getType() << std::endl;
		animal.makeSound();
		Cat cat1;
		std::cout << cat1.getType() << std::endl;
		cat1.makeSound();
		Cat cat2(cat1);
	}
	std::cout << "--- 2 ---" << std::endl;
	Animal* animal = new Animal();
	Animal* cat = new Cat();
	Animal* dog = new Dog();
	
	std::cout << "--- 3 ---" << std::endl;
	std::cout << animal->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;

	std::cout << "--- 4 ---" << std::endl;
	animal->makeSound();
	cat->makeSound();
	dog->makeSound();

	std::cout << "--- 5 ---" << std::endl;
	delete animal;
	delete cat;
	delete dog;

	std::cout << "--- 6 ---" << std::endl;
	WrongAnimal* wrongAnimal = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();

	std::cout << "--- 7 ---" << std::endl;
	std::cout << wrongAnimal->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;

	std::cout << "--- 8 ---" << std::endl;
	wrongAnimal->makeSound();
	wrongCat->makeSound();

	std::cout << "--- 9 ---" << std::endl;
	delete wrongAnimal;
	delete wrongCat;
}
