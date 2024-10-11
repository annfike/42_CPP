#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(Ice const & src) : AMateria(src)
{
    *this = src;
}

Ice::~Ice()
{}

Ice & Ice::operator=(Ice const & src)
{
    if (this != &src)
    {
        _type = src._type;
    }
    return (*this);
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

