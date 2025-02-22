/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:56:16 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/30 16:12:26 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type_ = "Dog";
	this->brain_ = new Brain();
}

Dog::Dog(const Dog &copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type_ = copy.get_type();
	this->brain_ = copy.brain_;
}

// Destructor
Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain_;
}

// Operators
Dog &Dog::operator=(Dog other) {
	// Copy & swap idiom
	Dog::swap(*this, other);
	return *this;
}

void Dog::swap(Dog &first, Dog &second) {
	std::swap(first.type_, second.type_);
	std::swap(first.brain_, second.brain_);
}

// Functions
void Dog::makeSound() const {
	std::cout << this->type_ << " barks!" << std::endl;
}

void Dog::implant_idea(std::string idea) {
	for (int i = 0; i < 100; i++) {
		if (this->brain_->get_idea(i) == "") {
			this->brain_->set_idea(i, idea);
			return;
		}
	}
	std::cout << "Brain of dog is full!" << std::endl;
}

void Dog::print_ideas() const {
	std::string str;
	std::cout << "Dog's ideas:" << std::endl;
	for (int i = 0; i < 100; i++) {
		str = this->brain_->get_idea(i);
		if (str.empty())
			return;
		std::cout << str << std::endl;
	}
}