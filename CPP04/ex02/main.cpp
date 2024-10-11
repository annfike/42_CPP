#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
const AAnimal* j = new Dog();
const AAnimal* c = new Cat();

std::cout << j->getType() << " " << std::endl;
std::cout << c->getType() << " " << std::endl;
c->makeSound(); //will output the cat sound!
j->makeSound();

delete j;
delete c;

AAnimal *arr[10];
for (int i = 0; i < 5; i++)
    arr[i] = new Dog();
for (int i = 5; i < 10; i++)
{
    arr[i] = new Cat();
    arr[i]->makeSound();
}
for (int i = 0; i < 10; i++)
    delete arr[i];

// не можем создать const AAnimal* a = new AAnimal();

return 0;
}