#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal 
{
    private:
        Brain *brain;

    public:
        Cat();
        Cat(const Cat &arg);
        ~Cat(); 
        Cat &operator=(const Cat &arg);
        void makeSound() const;
        std::string getIdea(int i) const;
        
 };

#endif