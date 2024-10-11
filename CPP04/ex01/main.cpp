#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* c = new Cat();

std::cout << "-------------------TYPE/SOUND/IDEAS--------------------------" << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << c->getType() << " " << std::endl;
c->makeSound(); //will output the cat sound!
j->makeSound();
std::cout << c->getIdea(0) << std::endl;
std::cout << c->getIdea(11) << std::endl;
std::cout << "---------------------------------------------" << std::endl;

delete j;
delete c;

std::cout << "-------------------ARRAY--------------------------" << std::endl;
Animal *arr[10];
for (int i = 0; i < 5; i++)
    arr[i] = new Dog();
for (int i = 5; i < 10; i++)
{
    arr[i] = new Cat();
    arr[i]->makeSound();
}
for (int i = 0; i < 10; i++)
    delete arr[i];

/*
Поверхностное копирование (shallow copy): При таком копировании создается новый объект, но его поля, которые ссылаются на другие объекты (например, указатели), копируются по ссылке. Это означает, что оба объекта будут ссылаться на один и тот же участок памяти. Если один из объектов изменит данные, это повлияет на другой объект.
Глубокое копирование (deep copy): При глубоком копировании создается новый объект, и все объекты, на которые ссылаются его поля, также копируются. Таким образом, каждый объект имеет свои собственные копии данных, и изменения в одном объекте не влияют на другой.*/

std::cout << "-------------------TEST DEEP COPY--------------------------" << std::endl;
Animal *cat1 = new Cat();
Animal *cat2 = new Cat(*static_cast<Cat*>(cat1)); // Используя static_cast<Cat*>(cat1), вы явно указываете компилятору, что хотите рассматривать cat1 как указатель на объект типа Cat. Это необходимо, если cat1 объявлен как указатель на базовый класс Animal, и вы хотите получить доступ к специфическим для Cat методам или свойствам.
Animal *cat3 = new Cat();
*cat3 = *cat1;
Cat cat4 = *static_cast<Cat*>(cat1);
std::cout << "cat1 type: " << cat1->getType() << std::endl;
std::cout << "cat2 type: " << cat2->getType() << std::endl;
std::cout << "cat3 type: " << cat3->getType() << std::endl;
std::cout << "cat4 type: " << cat4.getType() << std::endl;
delete cat1;
std::cout << "cat2 type after deleting cat1: " << cat2->getType() << std::endl;
std::cout << "cat3 type after deleting cat1: " << cat3->getType() << std::endl; 
std::cout << "cat4 type after deleting cat1: " << cat4.getType() << std::endl;
delete cat2;
delete cat3;
std::cout << "---------------------------------------------" << std::endl;

const Animal* a = new Animal();
std::cout << "a type: " << a->getType() << std::endl;
a->makeSound(); 
delete a;

// как это работает
Dog basic;
{
    Dog tmp = basic;
}

return 0;
}