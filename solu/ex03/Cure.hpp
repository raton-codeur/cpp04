/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:37:22 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/05 11:12:41 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria {
 public:	
  // Constructors
  Cure();
  Cure(const Cure &copy);

  // Destructor
  virtual ~Cure();

  // Operators
  Cure &operator=(Cure other);

	// Functions
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif