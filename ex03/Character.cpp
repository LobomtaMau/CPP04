#include "Character.hpp"

Character::Character(std::string const &name) : _name(name) {
    for (int i = 0; i < 4; i++)
        inventory[i] = nullptr;
    std::cout << "Character " << _name << " constructed.\n"; //name
}

Character::Character(const Character &other) : _name(other._name) {
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = nullptr;
    }
    std::cout << "Character copy constructor called.\n";
}

Character &Character::operator=(Character const &other) {
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; i++) {
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = nullptr;
        }
    }
    std::cout << "Character assigned.\n";
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        delete inventory[i];
    std::cout << "Character " << _name << " destructed.\n";
}

std::string const &Character::getName() const {
    return _name;
}


void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if( inventory[i] == nullptr) {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
        inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && inventory[idx] != nullptr)
        inventory[idx]->use(target);
}
