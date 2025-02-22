/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:15:00 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/05 11:16:39 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructors
AMateria::AMateria() : type_("") {
  this->wielder_ = NULL;
  this->materia_source_ = NULL;
  this->is_on_floor = false;
}

AMateria::AMateria(std::string const &type) : type_(type){
  this->wielder_ = NULL;
  this->materia_source_ = NULL;
  this->is_on_floor = false;
}

AMateria::AMateria(const AMateria &copy) : type_(copy.type_){
	this->wielder_ = NULL;
	this->materia_source_ = NULL;
  this->is_on_floor = false;
}

// Destructor
AMateria::~AMateria() {}

// Operators
AMateria &AMateria::operator=(const AMateria &other){
	this->type_ = other.type_;
	return *this;
}

std::string const &AMateria::getType() const { return this->type_; }

Character *AMateria::getWielder() const { return this->wielder_; }

void AMateria::setWielder(Character *new_wielder) {
  this->wielder_ = new_wielder;
}

MateriaSource *AMateria::getMateriaSource() const {
  return this->materia_source_;
}

void AMateria::setMateriaSource(MateriaSource *new_materia_source) {
  this->materia_source_ = new_materia_source;
}