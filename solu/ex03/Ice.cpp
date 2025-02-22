/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:42:10 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/05 11:18:14 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors
Ice::Ice() {
	this->type_ = "ice";
  this->wielder_ = NULL;
  this->materia_source_ = NULL;
}

Ice::Ice(const Ice &copy) {
	this->type_ = "ice";
  this->wielder_ = NULL;
  this->materia_source_ = NULL;
}

// Destructor
Ice::~Ice() {}

// Operators

Ice &Ice::operator=(Ice other) {
	std::cout << "Assigning an ice to another ice doesn't make sense." << std::endl;
  return *this;
}

// Functions
AMateria *Ice::clone() const {
  AMateria *temp = new Ice(*this);
  temp->setWielder(NULL);
	temp->setMateriaSource(NULL);
  return temp;
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
