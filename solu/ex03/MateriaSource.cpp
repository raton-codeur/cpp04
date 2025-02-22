/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:23:04 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/05 10:20:42 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++) this->memory_[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
  for (int i = 0; i < 4; i++) {
    if (copy.memory_[i]) {
      this->memory_[i] = copy.memory_[i]->clone();
      this->memory_[i]->setMateriaSource(this);
    } else
      this->memory_[i] = NULL;
  }
}

// Destructor
MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    if (this->memory_[i]) delete this->memory_[i];
  }
}

// Operators
MateriaSource &MateriaSource::operator=(MateriaSource other) {
  MateriaSource::swap(*this, other);
  return *this;
}

void MateriaSource::swap(MateriaSource &first, MateriaSource &second) {
  std::swap(first.memory_, second.memory_);
}

// Getters & Setters
AMateria *MateriaSource::getMemory(int idx) const {
	if (idx < 0 || idx > 3)
		return NULL;
	return this->memory_[idx];
}

void MateriaSource::setMemory(int idx, AMateria *materia) {
	if (idx < 0 || idx > 3)
		return;
	this->memory_[idx] = materia;
}

// Functions
void MateriaSource::learnMateria(AMateria *materia) {
  for (int i = 0; i < 4; i++) {
    if (this->memory_[i] == NULL) {
      this->memory_[i] = materia;
      materia->setMateriaSource(this);
      std::cout << "Materia source learned " << materia->getType() << "!"
                << std::endl;
      return;
    }
  }
  std::cout << "Couldn't learn " << materia->getType()
            << ", because materia source is full." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 3; i >= 0; i--) {
		if (this->memory_[i] && this->memory_[i]->getType() == type) {
			std::cout << "Materia source creates " << type << std::endl;
			return this->memory_[i]->clone();
		}
	}
	std::cout << "Materia source cannot create " << type << ". Not learned." << std::endl;
	return NULL;
}
