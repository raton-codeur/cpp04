/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:53:04 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/30 11:06:03 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal {
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
};

#endif