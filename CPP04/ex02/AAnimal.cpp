#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &arg)
{
    std::cout << "AAnimal Copy constructor called" << std::endl;
    *this = arg;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &arg)
{
    std::cout << "AAnimal Assignation operator called" << std::endl;
    type = arg.type;
    return *this;
}

std::string AAnimal::getType() const
{
    return type;
}

/*void    AAnimal::makeSound() const
{
     std::cout << "I have no sound" << std::endl;    
}*/


