/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:13:57 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/05 11:30:10 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"

class Character : public ICharacter {
 public:
	// Constructors
	Character();
	Character(std::string name);
	Character(const Character &copy);

	// Destructor
	virtual ~Character();

	// Operators
	void swap(Character &first, Character &second);
	Character &operator=(const Character &other);

	// Getters & Setters
	std::string const &getName() const;
	void setName(std::string name);
	AMateria *getInventory(int idx) const;
	void setInventory(int idx, AMateria *materia);


	// Functions
	virtual void equip(AMateria *m);
	virtual void equip_from_floor(int idx);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
	
	static AMateria *floor_[50];
	
 private:
	std::string name_;
	AMateria *inventory_[4];
	static int n_characters_;
};

#endif