/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:56:16 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/01 15:04:26 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type_ = "Cat";
	this->brain_ = new Brain();
}

Cat::Cat(const Cat &copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type_ = copy.get_type();
	this->brain_ = new Brain(*copy.brain_);
}

// Destructor
Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain_;
}

// Operators
Cat &Cat::operator=(Cat other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	// Copy & swap idiom
	Cat::swap(*this, other);
	return *this;
}

void Cat::swap(Cat &first, Cat &second) {
	std::swap(first.type_, second.type_);
	std::swap(first.brain_, second.brain_);
}

// Functions
void Cat::makeSound() const {
	std::cout << this->type_ << " meows!" << std::endl;
}

void Cat::implant_idea(std::string idea) {
	for (int i = 0; i < 100; i++) {
		if (this->brain_->get_idea(i) == "") {
			this->brain_->set_idea(i, idea);
			return;
		}
	}
	std::cout << "Brain of cat is full!" << std::endl;
}

void Cat::print_ideas() const {
	std::string str;
	std::cout << "Cat's ideas:" << std::endl;
	for (int i = 0; i < 100; i++) {
		str = this->brain_->get_idea(i);
		if (str.empty())
			return;
		std::cout << str << std::endl;
	}
}