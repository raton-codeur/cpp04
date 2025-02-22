/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:56:16 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/30 13:31:01 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type_ = "Cat";
}

Cat::Cat(const Cat &copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type_ = copy.get_type();
}

// Destructor
Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

// Operators
Cat &Cat::operator=(Cat other) {
	// Copy & swap idiom
	Cat::swap(*this, other);
	return *this;
}

void Cat::swap(Cat &first, Cat &second) {
	std::swap(first.type_, second.type_);
}

// Functions
void Cat::makeSound() const {
	std::cout << this->type_ << " meows!" << std::endl;
}