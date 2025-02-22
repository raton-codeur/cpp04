#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "--- 0 ---" << std::endl;
	{
		Cat cat1;
		Cat cat2(cat1);
	}

	std::cout << "--- 1 ---" << std::endl;
	{
		Dog dog1;
		{
			Dog dog2 = dog1;
		}
		std::cout << "dog2 has been destroyed" << std::endl;
	}

	std::cout << "--- 2 ---" << std::endl;
	Animal* animal = new Animal();
	Cat* cat = new Cat();
	Dog* dog = new Dog();

	std::cout << "--- 3 ---" << std::endl;
	delete animal;
	delete cat;
	delete dog;
}
