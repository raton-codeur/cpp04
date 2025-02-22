/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:53:15 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/30 10:53:17 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	type_ = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type) {
	std::cout << "WrongAnimal type constructor called" << std::endl;
	type_ = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	type_ = copy.get_type();
}

// Destructor
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

// Operators
void WrongAnimal::swap(WrongAnimal &first, WrongAnimal &second) {
  std::swap(first.type_, second.type_);
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal other) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
  // Copy & Swap idiom
  WrongAnimal::swap(*this, other);
  return *this;
}

// Getters / Setters
std::string WrongAnimal::get_type() const { return type_; }
void WrongAnimal::set_type(std::string type) { type_ = type; }

// Functions

void WrongAnimal::makeSound() const {
	std::cout << this->type_ << " makes a WrongAnimal sound" << std::endl;
}