#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(std::string name);
        ~Weapon();
        const std::string getType() const; //Объявление метода как const гарантирует, что он не изменит состояние объекта, на котором он вызывается. Это означает, что внутри этого метода не будет изменений значений членов класса. Это важно для обеспечения безопасности и предсказуемости кода.
        void  setType(std::string new_type);
};


#endif

