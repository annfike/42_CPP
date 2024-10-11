#include <iostream>
#include "Cat.hpp"

Cat::Cat(): AAnimal()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &arg): AAnimal(arg)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    brain = new Brain();
    *this = arg;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &arg)
{
    std::cout << "Cat Assignation operator called" << std::endl;
    if (this != &arg)
    {
        type = arg.type;
        delete brain;
        brain = new Brain(*arg.brain);
    }
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "Myau!" << std::endl;
}

std::string Cat::getIdea(int i) const
{
    return brain->getIdea(i);
}
