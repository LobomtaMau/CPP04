#include "Animal.hpp"

Animal::Animal()
    : _type("Animal") {}

Animal::~Animal() {}

void Animal::makeSound() const {
    std::cout << "Animal sound.\n";
}

std::string Animal::getType() const {
    return _type;
}
