/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:53:04 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/01 11:26:21 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
 public:
	// Constructors
	Dog();
	Dog(const Dog &copy);
	
	// Destructor
	~Dog();

	// Operators
	Dog &operator=(Dog other);
	void swap(Dog &first, Dog &second);

	// Functions
	void makeSound() const;
	void implant_idea(std::string idea);
	void print_ideas() const;

 private:
	Brain *brain_;
};

#endif