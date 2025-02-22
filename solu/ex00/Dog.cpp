/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:56:16 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/30 11:06:07 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type_ = "Dog";
}

Dog::Dog(const Dog &copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type_ = copy.get_type();
}

// Destructor
Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

// Operators
Dog &Dog::operator=(Dog other) {
	// Copy & swap idiom
	Dog::swap(*this, other);
	return *this;
}

void Dog::swap(Dog &first, Dog &second) {
	std::swap(first.type_, second.type_);
}

// Functions
void Dog::makeSound() const {
	std::cout << this->type_ << " barks!" << std::endl;
}