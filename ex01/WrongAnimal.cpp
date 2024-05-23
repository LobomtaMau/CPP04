#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
    : _type("WrongAnimal") {}

WrongAnimal::~WrongAnimal() {}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound.\n";
}

std::string WrongAnimal::getType() const {
    return _type;
}