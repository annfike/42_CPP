#ifndef AANIMAL_HPP
# define AANIMAL_HPP

//https://metanit.com/cpp/tutorial/5.12.php

#include <iostream>

class AAnimal {
    protected:
        std::string type;
    public:
        AAnimal(); 
        AAnimal(const AAnimal &arg);
        virtual ~AAnimal(); // Объявление деструктора как виртуального гарантирует, что при уничтожении объекта производного класса будет корректно вызван деструктор базового класса Animal
        AAnimal &operator=(const AAnimal &arg); 
        std::string     getType() const;
		virtual void    makeSound() const = 0; // Ключевое слово virtual позволяет переопределять этот метод в наследуемых классах. 
        //Также const указывает, что метод не изменяет состояние объекта.
        //Класс, который определяет или наследует виртуальную функцию, еще назвается полиморфным (polymorphic class)
 };

#endif