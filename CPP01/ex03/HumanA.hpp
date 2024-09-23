#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon &weapon; // ссылка не мб нулевая
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack();
};


#endif