/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:37:22 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/05 11:18:04 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria {
 public:	
  // Constructors
  Ice();
  Ice(const Ice &copy);

  // Destructor
  virtual ~Ice();

  // Operators
  Ice &operator=(Ice other);

	// Functions
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif