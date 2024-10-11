#include <iostream>
#include "Dog.hpp"

Dog::Dog(): AAnimal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &arg): AAnimal(arg)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    brain = new Brain();
    *this = arg;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &arg)
{
    std::cout << "Dog Assignation operator called" << std::endl;
    if (this != &arg)
    {
        type = arg.type;
        delete brain;
        brain = new Brain(*arg.brain);
    }
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "Gav!" << std::endl;
}

std::string Dog::getIdea(int i) const
{
    return brain->getIdea(i);
}