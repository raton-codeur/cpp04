/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:56:16 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/30 13:31:01 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type_ = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type_ = copy.get_type();
}

// Destructor
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

// Operators
WrongCat &WrongCat::operator=(WrongCat other) {
	// Copy & swap idiom
	WrongCat::swap(*this, other);
	return *this;
}

void WrongCat::swap(WrongCat &first, WrongCat &second) {
	std::swap(first.type_, second.type_);
}

// Functions
void WrongCat::makeSound() const {
	std::cout << this->type_ << " meows like a WrongCat!" << std::endl;
}