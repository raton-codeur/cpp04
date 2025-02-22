/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:25:45 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/01 11:50:07 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
	// Instantiating an animal doesn't work:
	//AAnimal *animal1 = new AAnimal();
	//AAnimal animal2 = AAnimal();

	// Rest ist still working fine:
	
	std::cout << DEFAULT << std::endl << "--- PDF: ---" << std::endl
            << std::endl;
  Dog *dog = new Dog();
  Cat *cat = new Cat();

  delete dog;
  delete cat;

  std::cout << std::endl
            << GREEN << "--- Array of animals ---" << std::endl
            << std::endl;

  AAnimal *array_animals[10];
  for (int i = 0; i < 10; i++) {
    if (i % 2)
      array_animals[i] = new Dog();
    else
      array_animals[i] = new Cat();
  }
  std::cout << std::endl << YELLOW;

  for (int i = 0; i < 10; i++) array_animals[i]->makeSound();

  std::cout << std::endl << RED;

  for (int i = 0; i < 10; i++) delete array_animals[i];

  std::cout << std::endl
            << BLUE << "--- Test for deep copy ---" << std::endl
            << std::endl;
  Cat *cat2 = new Cat();
  cat2->implant_idea("Hmm... fish!");
  cat2->implant_idea("I wanna play...");
  cat2->print_ideas();

  std::cout << std::endl
            << MAGENTA << "--- Making a deep copy ---" << std::endl
            << std::endl;

  Cat *cat3 = new Cat(*cat2);
  cat2->implant_idea("Gotta sleep now...");
  std::cout << std::endl;
  cat2->print_ideas();
  std::cout << std::endl;
  cat3->print_ideas();
  std::cout << std::endl;

  std::cout << std::endl
            << CYAN << "--- Copy assignment operator ---" << std::endl
            << std::endl;

	std::cout << "New Cat" << std::endl << std::endl;
  Cat *cat4 = new Cat();
	std::cout << std::endl <<"Assigning cat 3 to cat 4" << std::endl << std::endl;
  *cat4 = *cat3;
	std::cout << std::endl ;
  cat4->print_ideas();
  std::cout << std::endl;
  cat3->implant_idea("No sleeping now!!!");
  cat3->print_ideas();
  std::cout << std::endl;
  cat4->print_ideas();
  std::cout << std::endl;

	std::cout << std::endl
            << DEFAULT << "--- Destruction ---" << std::endl
            << std::endl;

  delete cat2;
  delete cat3;
  delete cat4;
  return 0;
}