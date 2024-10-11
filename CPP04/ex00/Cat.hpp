#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal 
{
    private:

    public:
        Cat();
        Cat(const Cat &arg);
        ~Cat(); 
        Cat &operator=(const Cat &arg);
        void makeSound() const;

 };

#endif