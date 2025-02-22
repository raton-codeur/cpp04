/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:53:09 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/30 14:03:38 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class Animal {
 public:
  // Constructors
  Animal();
  Animal(const Animal &copy);
  Animal(std::string type);

  // Destructor
  virtual ~Animal();

  // Operators
  Animal &operator=(Animal other);
  void swap(Animal &first, Animal &second);

  // Getters / Setters
  std::string get_type() const;
  void set_type(std::string type);

  // Functions
  virtual void makeSound() const;

 protected:
  std::string type_;
};

#endif