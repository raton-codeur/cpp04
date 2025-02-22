/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:56 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/05 11:40:52 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>
#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"

class Character;
class ICharacter;
class MateriaSource;
class IMateriaSource;

class AMateria {
 public:
	// Constructors
	AMateria();
 	AMateria(std::string const &type);
	AMateria(const AMateria &copy);

	// Destructor
	virtual ~AMateria();
	
	// Operators
	AMateria &operator=(const AMateria &other);
	
	// Getters & Setters
	std::string const &getType() const;
	Character *getWielder() const;
	void setWielder(Character *new_wielder);
	MateriaSource *getMateriaSource() const;
	void setMateriaSource(MateriaSource *new_materia_source);
	
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target) = 0;
	
 protected:
	std::string type_;
	Character *wielder_;
	MateriaSource *materia_source_;
	bool is_on_floor;
};

#endif