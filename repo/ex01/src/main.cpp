#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "--- 0 ---" << std::endl;
	{
		Cat cat1;
		{
			Cat cat2(cat1);
		}
	}

	std::cout << "--- 1 ---" << std::endl;
	{
		Dog dog1;
		{
			Dog dog2;
			dog2 = dog1;
		}
	}

	Animal* animals[10];
	
	std::cout << "--- 2 ---" << std::endl;
	for (int i = 0; i < 5; i++)
		animals[i] = new Cat();

	std::cout << "--- 3 ---" << std::endl;
	for (int i = 5; i < 10; i++)
		animals[i] = new Dog();

	std::cout << "--- 4 ---" << std::endl;
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();

	std::cout << "--- 5 ---" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
}
