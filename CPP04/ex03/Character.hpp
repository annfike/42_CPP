#ifndef CHARACTER_HPP   
#define CHARACTER_HPP

#include <iostream>

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria* _materia[4];
        //AMateria* _materia_on_the_floor[4];
    public:
        Character();
        Character(std::string const & name);
        Character(Character const & src);
        ~Character();
        Character & operator=(Character const & src);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        AMateria* getMateria(int idx);
        void printMaterias() const; // Функция для печати содержимого массива _materia
};

#endif