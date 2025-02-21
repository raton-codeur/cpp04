#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "--- 1 ---" << std::endl;
	Animal* animal = new Animal();
	Animal* cat = new Cat();
	Animal* dog = new Dog();
	
	std::cout << "--- 2 ---" << std::endl;
	std::cout << animal->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;

	std::cout << "--- 3 ---" << std::endl;
	animal->makeSound();
	cat->makeSound();
	dog->makeSound();

	std::cout << "--- 4 ---" << std::endl;
	delete animal;
	delete cat;
	delete dog;

	std::cout << "--- 5 ---" << std::endl;
	WrongAnimal* wrongAnimal = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();

	std::cout << "--- 6 ---" << std::endl;
	std::cout << wrongAnimal->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;

	std::cout << "--- 7 ---" << std::endl;
	wrongAnimal->makeSound();
	wrongCat->makeSound();

	std::cout << "--- 8 ---" << std::endl;
	delete wrongAnimal;
	delete wrongCat;
}
