#include <iostream>
#include "Dog.hpp"

Dog::Dog(): Animal()
{
    type = "Dog";
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &arg): Animal(arg)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = arg;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &arg)
{
    std::cout << "Dog Assignation operator called" << std::endl;
    type = arg.type;
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "Gav!" << std::endl;
}