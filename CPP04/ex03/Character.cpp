#include "Character.hpp"

Character::Character() : _name("default")
{
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

Character::Character(Character const & src)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i])
            delete _materia[i];
        if (src._materia[i])
            _materia[i] = src._materia[i]->clone();
        else
            _materia[i] = NULL;
    }
    _name = src._name;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i])
            delete _materia[i];
    }
}

Character & Character::operator=(Character const & src)
{
    if (this != &src)
    {
        _name = src._name;
        for (int i = 0; i < 4; i++)
        {
            if (_materia[i])
                delete _materia[i];
            if (src._materia[i])
                _materia[i] = src._materia[i]->clone();
            else
                _materia[i] = NULL;
        }
    }
    return (*this);
}

std::string const & Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_materia[i])
        {
            _materia[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        _materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _materia[idx])
        _materia[idx]->use(target);
}

AMateria* Character::getMateria(int idx)
{
    if (idx >= 0 && idx < 4)
        return (_materia[idx]);
    return (NULL);
}

void Character::printMaterias() const
{
    std::cout << "Materias for character " << _name << ":" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i])
            std::cout << "  Slot " << i << ": " << _materia[i]->getType() << std::endl;
        else
            std::cout << "  Slot " << i << ": Empty" << std::endl;
    }
}

