#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string type;
    public:
        Animal(); 
        Animal(const Animal &arg);
        virtual ~Animal(); // Объявление деструктора как виртуального гарантирует, что при уничтожении объекта производного класса будет корректно вызван деструктор базового класса Animal
        Animal &operator=(const Animal &arg); 
        std::string     getType() const;
		virtual void    makeSound() const; // Ключевое слово virtual позволяет переопределять этот метод в наследуемых классах. 
        //Также const указывает, что метод не изменяет состояние объекта.
        //Класс, который определяет или наследует виртуальную функцию, еще назвается полиморфным (polymorphic class)
        virtual std::string getIdea(int i) const;
 };

#endif