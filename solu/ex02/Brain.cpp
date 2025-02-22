#include "Brain.hpp"

// Constructors
Brain::Brain() {
  std::cout << "Brain default constructor called" << std::endl;
  this->ideas_ = new std::string[100];
}

Brain::Brain(const Brain &copy) {
  std::cout << "Brain copy constructor called" << std::endl;
  if (!copy.ideas_) return;
	this->ideas_ = new std::string[100];
  for (int i = 0; i < 100; i++) {
    this->ideas_[i] = copy.ideas_[i];
  }
}

// Destructor
Brain::~Brain() {
  std::cout << "Brain destructor called" << std::endl;
  if (ideas_) delete[] ideas_;
}

// Operators
Brain &Brain::operator=(Brain other) {
  Brain::swap(*this, other);
  return *this;
}

void Brain::swap(Brain &first, Brain &second) {
  std::swap(first.ideas_, second.ideas_);
}

// Getters & Setters
std::string Brain::get_idea(unsigned int index) const {
  if (index > 99) {
    std::cout << "Can't get idea " << index << ". Index out of range!"
              << std::endl;
    return "";
  }
  return this->ideas_[index];
}

void Brain::set_idea(unsigned int index, std::string idea) {
  if (index > 99) {
    std::cout << "Can't set idea " << index << ". Index out of range!"
              << std::endl;
    return;
  }
  this->ideas_[index] = idea;
}
