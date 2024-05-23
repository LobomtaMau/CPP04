#include "WrongCat.hpp"

WrongCat::WrongCat() {
    _type = "WrongCat";
}

WrongCat::~WrongCat() {}
        
void WrongCat::makeSound() const {
    std::cout << "WrongCat blablabla!\n";
}