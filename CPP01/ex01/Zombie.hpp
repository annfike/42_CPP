#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
# include <sstream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
        void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif

/*
The Zombie Class has a default constructor.? why
В некоторых ситуациях может быть удобно создавать объекты без необходимости указывать имя. 
Это упрощает код, особенно если вы хотите создать массив или коллекцию зомби, где не все экземпляры требуют уникальных имен.
*/