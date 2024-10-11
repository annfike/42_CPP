#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &arg)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = arg;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &arg)
{
    std::cout << "WrongAnimal Assignation operator called" << std::endl;
    type = arg.type;
    return *this;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void    WrongAnimal::makeSound() const
{
     std::cout << "I'm wrong animal. I have no sound" << std::endl;    
}

