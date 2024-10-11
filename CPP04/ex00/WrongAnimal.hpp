#ifndef WRONGWrongAnimal_HPP
# define WRONGWrongAnimal_HPP

#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal(); 
        WrongAnimal(const WrongAnimal &arg);
        ~WrongAnimal(); 
        WrongAnimal &operator=(const WrongAnimal &arg); 
        std::string     getType() const;
		void    makeSound() const;
 };

#endif