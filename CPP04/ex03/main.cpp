#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <string>

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    std::cout << "-------MORE TESTS--------------" << std::endl;
    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    src2->learnMateria(new Cure());
    src2->learnMateria(new Ice());
    ICharacter* me2 = new Character("Kitana");
    ICharacter* me3 = new Character("Milena");
    AMateria* tmp2;
    tmp2 = src2->createMateria("ice");
    me2->equip(tmp2);
    tmp2 = src2->createMateria("cure");
    me2->equip(tmp2);
    tmp2 = src2->createMateria("ice");
    me2->equip(tmp2);
    tmp2 = src2->createMateria("fire");
    me2->equip(tmp2);
    ((Character*)me2)->printMaterias();
    me2->use(0, *me3);
    me2->use(1, *me3);
    me2->use(2, *me3);
    me2->use(3, *me3); // Should not work
    me2->use(4, *me3); // Should not work
    AMateria *f = ((Character*)me2)->getMateria(0);
    me2->unequip(0);
    ((Character*)me2)->printMaterias();
    me2->use(0, *me3); // Should not work

    delete me3;
    delete me2;
    delete src2;
    delete f;


        
    return 0;
}