#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        // cpy
        virtual ~Dog();

        void makeSound() const;
};

#endif