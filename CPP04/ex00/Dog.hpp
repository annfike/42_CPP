#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal 
{
    private:

    public:
        Dog();
        Dog(const Dog &arg);
        ~Dog(); 
        Dog &operator=(const Dog &arg);
        void makeSound() const;

 };

#endif