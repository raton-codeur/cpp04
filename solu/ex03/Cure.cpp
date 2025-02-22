/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:42:10 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/02 11:55:43 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructors
Cure::Cure(){
	this->type_ = "cure";
  this->wielder_ = NULL;
	this->materia_source_ = NULL;
}

Cure::Cure(const Cure &copy) {
	this->type_ = "cure";
  this->wielder_ = NULL;
	this->materia_source_ = NULL;
}

// Destructor
Cure::~Cure() {}

// Operators
Cure &Cure::operator=(Cure other) {
	std::cout << "Assigning a cure to another cure doesn't make sense." << std::endl;
	(void) other;
  return *this;
}

// Functions
AMateria *Cure::clone() const {
  AMateria *temp = new Cure(*this);
  temp->setWielder(NULL);
	temp->setMateriaSource(NULL);
	return temp;
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "’s wounds *"
            << std::endl;
}
