#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(Cure const & src) : AMateria(src)
{
    *this = src;
}

Cure::~Cure()
{}

Cure & Cure::operator=(Cure const & src)
{
    if (this != &src)
    {
        _type = src._type;
    }
    return (*this);
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
