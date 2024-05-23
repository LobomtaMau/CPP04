#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
}

Dog::~Dog() {}
        
void Dog::makeSound() const {
    std::cout << "woooooooff!\n";
}