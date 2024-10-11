#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal 
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &arg);
        ~Dog(); 
        Dog &operator=(const Dog &arg);
        void makeSound() const;
        std::string getIdea(int i) const;
 };

#endif