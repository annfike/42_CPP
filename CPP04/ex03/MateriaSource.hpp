#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _materia[4];
    public:
        MateriaSource();
        MateriaSource(MateriaSource const & src);
        ~MateriaSource();
        MateriaSource & operator=(MateriaSource const & src);
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};

#endif