/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:53:04 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/30 13:59:41 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
	// Constructors
	WrongCat();
	WrongCat(const WrongCat &copy);
	
	// Destructor
	~WrongCat();

	// Operators
	WrongCat &operator=(WrongCat other);
	void swap(WrongCat &first, WrongCat &second);

	// Functions
	void makeSound() const;
};

#endif