/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:53:09 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/30 13:58:38 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
 public:
  // Constructors
  WrongAnimal();
  WrongAnimal(const WrongAnimal &copy);
  WrongAnimal(std::string type);

  // Destructor
  ~WrongAnimal();

  // Operators
  WrongAnimal &operator=(WrongAnimal other);
  void swap(WrongAnimal &first, WrongAnimal &second);

  // Getters / Setters
  std::string get_type() const;
  void set_type(std::string type);

  // Functions
  void makeSound() const;

 protected:
  std::string type_;
};

#endif