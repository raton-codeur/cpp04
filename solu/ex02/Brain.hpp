#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
 public:
  // Constructors
  Brain();
  Brain(const Brain &copy);

  // Destructor
  ~Brain();

  // Operators
  void swap(Brain &first, Brain &second);
  Brain &operator=(Brain other);

	// Getters & Setters
	std::string get_idea(unsigned int index) const;
	void set_idea(unsigned int index, std::string idea);

 private:
  std::string *ideas_;
};

#endif