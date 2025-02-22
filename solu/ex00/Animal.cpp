/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:53:15 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/30 14:15:12 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors
Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
	type_ = "Animal";
}

Animal::Animal(std::string type) {
	std::cout << "Animal type constructor called" << std::endl;
	type_ = type;
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	type_ = copy.get_type();
}

// Destructor
Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

// Operators
void Animal::swap(Animal &first, Animal &second) {
  std::swap(first.type_, second.type_);
}

Animal &Animal::operator=(Animal other) {
	std::cout << "Animal copy assignment operator called" << std::endl;
  // Copy & Swap idiom
  Animal::swap(*this, other);
  return *this;
}

// Getters / Setters
std::string Animal::get_type() const { return type_; }
void Animal::set_type(std::string type) { type_ = type; }

// Functions

void Animal::makeSound() const {
	std::cout << this->type_ << " makes a sound" << std::endl;
}