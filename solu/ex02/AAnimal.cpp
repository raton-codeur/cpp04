/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:53:15 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/01 11:23:55 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructors
AAnimal::AAnimal() {
	std::cout << "AAnimal default constructor called" << std::endl;
	type_ = "AAnimal";
}

AAnimal::AAnimal(std::string type) {
	std::cout << "AAnimal type constructor called" << std::endl;
	type_ = type;
}

AAnimal::AAnimal(const AAnimal &copy) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	type_ = copy.get_type();
}

// Destructor
AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	this->type_ = other.type_;
  return *this;
}

// Getters / Setters
std::string AAnimal::get_type() const { return type_; }
void AAnimal::set_type(std::string type) { type_ = type; }

// Functions

void AAnimal::makeSound() const {
	std::cout << this->type_ << " makes a sound" << std::endl;
}