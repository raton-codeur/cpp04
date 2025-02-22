/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:46:41 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/05 10:19:30 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 public:
	// Constructors
	MateriaSource();
	MateriaSource(const MateriaSource &copy);

	// Destructor
  virtual ~MateriaSource();

	// Operators
	MateriaSource &operator=(MateriaSource other);
	void swap(MateriaSource &first, MateriaSource &second);

	// Getters & Setters
	AMateria *getMemory(int idx) const;
	void setMemory(int idx, AMateria *materia);

	// Functions
  virtual void learnMateria(AMateria *materia);
  virtual AMateria *createMateria(std::string const& type);

 private:
	AMateria *memory_[4];
};

#endif