/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:48:21 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/05 11:40:38 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int Character::n_characters_ = 0;
AMateria *Character::floor_[50] = {NULL};

// Constructors
Character::Character() {
	std::cout << "Character default constructor called" << std::endl;
  // if this is the first character to be created, initiate static variable
  // floor_
  n_characters_++;
  for (int i = 0; i < 4; i++) inventory_[i] = NULL;
  name_ = "nameless hero";
}

Character::Character(std::string name) {
	std::cout << "Character name constructor called" << std::endl;
  n_characters_++;
  for (int i = 0; i < 4; i++) inventory_[i] = NULL;
  this->name_ = name;
}

Character::Character(const Character &copy) {
	std::cout << "Character copy construtor called" << std::endl;
  n_characters_++;
  this->name_ = copy.name_;
  for (int i = 0; i < 4; i++) {
    if (copy.inventory_[i]) {
      this->inventory_[i] = copy.inventory_[i]->clone();
      this->inventory_[i]->setWielder(this);
    } else {	
      this->inventory_[i] = NULL;
		}
  }
}

// Destructor
Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
  n_characters_--;
  for (int i = 0; i < 4; i++) {
    if (this->inventory_[i]) delete this->inventory_[i];
  }

  // If no characters are left, delete items on the floor
  if (n_characters_ == 0) {
    std::cout << "All characters are gone. Items on the floor disappear."
              << std::endl;
    for (int i = 0; i < 50; i++) {
      if (floor_[i]) {
        delete floor_[i];
        floor_[i] = NULL;
      }
    }
  }
}

// Operators
void Character::swap(Character &first, Character &second) {
  std::swap(first.name_, second.name_);
  std::swap(first.inventory_, second.inventory_);
}

Character &Character::operator=(const Character &other) {
	std::cout << "Character copy assignment operator called" << std::endl;
	Character tmp = Character(other);
  Character::swap(*this, tmp);
  return *this;
}

// Getters & Setters
std::string const &Character::getName() const { return this->name_; }

void Character::setName(std::string name) { this->name_ = name; }

AMateria *Character::getInventory(int idx) const {
	if (idx < 0 || idx > 3)
		return NULL;
	return this->inventory_[idx];
}

void Character::setInventory(int idx, AMateria *materia) {
	if (idx < 0 || idx > 3)
		return;
	this->inventory_[idx] = materia;
}

// Functions
void Character::equip(AMateria *m) {
  // Check for existence
  if (!m) {
    std::cout << "Materia doesn't exist!" << std::endl;
    return;
  }
  // Checks if the materia is already wielded
  if (m->getWielder()) {
    std::cout << m->getType() << " is still equipped to "
              << m->getWielder()->getName()
              << ". Can't equip it to another slot!" << std::endl;
    return;
  }
  // Checks if the materia is already in a materia source
  if (m->getMateriaSource()) {
    std::cout << m->getType()
              << " is already equipped to a materia source. Can't equip it to "
                 "another slot!"
              << std::endl;
    return;
  }
  // Search for empty slot to equip
  for (int i = 0; i < 4; i++) {
    if (this->inventory_[i] == NULL) {
      this->inventory_[i] = m;
      m->setWielder(this);
      std::cout << this->getName() << " equipped " << m->getType() << ". (slot "
                << i << ")" << std::endl;
      return;
    }
  }
  // If there is no empty slot in inventory it falls onto the ground
  for (int i = 0; i < 50; i++) {
    if (Character::floor_[i] == NULL) {
      floor_[i] = m;
      floor_[i]->setWielder(NULL);
      std::cout << this->name_ << "'s inventory is full. Can't equip "
                << m->getType() << ". It falls onto the floor! (location: " << i
                << ")" << std::endl;
      return;
    }
  }
  std::cout << this->name_
            << "'s inventory is full. The materia falls onto the ground and "
               "shatters, as the floor is already full of other materias!"
            << std::endl;
	delete m;
}

void Character::equip_from_floor(int idx) {
  if (idx < 0 || idx > 49) {
    std::cout << "Invalid floor index!" << std::endl;
    return;
  }
  if (this->floor_[idx] == NULL) {
    std::cout << "There is nothing at this spot on the floor to equip!"
              << std::endl;
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (this->inventory_[i] == NULL) {
      this->inventory_[i] = this->floor_[idx];
      this->inventory_[i]->setWielder(this);
      this->floor_[idx] = NULL;
      std::cout << this->getName() << " equipped "
                << this->inventory_[i]->getType() << ". (slot " << i << ")"
                << std::endl;
      return;
    }
  }
  // If there is no empty slot in inventory:
  std::cout << this->name_ << "'s inventory is full. Can't equip "
            << this->floor_[idx]->getType() << std::endl;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 3) {
    std::cout << "Invalid inventory index!" << std::endl;
    return;
  }
  if (this->inventory_[idx] == NULL) {
    std::cout << "Inventory slot already empty!" << std::endl;
    return;
  }
  int i;
  for (i = 0; i < 50; i++) {
    if (Character::floor_[i] == NULL) {
      floor_[i] = this->inventory_[i];
      floor_[i]->setWielder(NULL);
      std::cout << "Materia is unequipped and falls on the ground! (location: "
                << i << ")" << std::endl;
      break;
    }
  }
  if (i == 50) {
    std::cout << "Too many materias on the floor. The hero can't move their "
                 "arms to unequip the item!"
              << std::endl;
    return;
  }
  this->inventory_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || idx > 3) {
    std::cout << "Invalid inventory index!" << std::endl;
    return;
  }
  if (this->inventory_[idx] == NULL) {
    std::cout << "Slot " << idx << " is empty!" << std::endl;
    return;
  }
	std::cout << name_ << ": ";
  this->inventory_[idx]->use(target);
  delete this->inventory_[idx];
  this->inventory_[idx] = NULL;
}
