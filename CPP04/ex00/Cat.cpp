#include <iostream>
#include "Cat.hpp"

Cat::Cat(): Animal()
{
    type = "Cat";
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &arg): Animal(arg)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = arg;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &arg)
{
    std::cout << "Cat Assignation operator called" << std::endl;
    type = arg.type;
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "Myau!" << std::endl;
}