#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &arg): WrongAnimal(arg)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = arg;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &arg)
{
    std::cout << "WrongCat Assignation operator called" << std::endl;
    type = arg.type;
    return *this;
}

void    WrongCat::makeSound() const
{
    std::cout << "Wrong Myau!" << std::endl;
}