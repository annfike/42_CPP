#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* w = new WrongAnimal();
    const WrongAnimal* k = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << meta->getType() << " " << std::endl;
    std::cout << w->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    w->makeSound();
    k->makeSound();

    delete meta;
    delete j;
    delete i;
    delete w;
    delete k;


    return 0;
}