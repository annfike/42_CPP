#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal 
{
    private:

    public:
        WrongCat();
        WrongCat(const WrongCat &arg);
        ~WrongCat(); 
        WrongCat &operator=(const WrongCat &arg);
        void makeSound() const;

 };

#endif