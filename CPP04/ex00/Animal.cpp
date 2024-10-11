#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &arg)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = arg;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &arg)
{
    std::cout << "Animal Assignation operator called" << std::endl;
    type = arg.type;
    return *this;
}

std::string Animal::getType() const
{
    return type;
}

void    Animal::makeSound() const
{
     std::cout << "I have no sound" << std::endl;    
}


