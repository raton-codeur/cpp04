/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:53:09 by lschrafs          #+#    #+#             */
/*   Updated: 2022/10/01 11:24:18 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AAAnimal_HPP
#define AAAnimal_HPP

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

class AAnimal {
 public:
  // Constructors
  AAnimal();
  AAnimal(const AAnimal &copy);
  AAnimal(std::string type);

  // Destructor
  virtual ~AAnimal();

  // Operators
  AAnimal &operator=(const AAnimal &other);

  // Getters / Setters
  std::string get_type() const;
  void set_type(std::string type);

  // Functions
  virtual void makeSound() const = 0;

 protected:
  std::string type_;
};

#endif