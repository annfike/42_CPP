#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int value;
        static const int number_of_bits = 8;
    public:
        Fixed(); //Default constructor
        Fixed(const int value);
	    Fixed(const float value);
        Fixed(const Fixed &fixed); //Copy constructor
        ~Fixed(); //Destructor
        Fixed &operator=(const Fixed &fixed); //Assignation operator
                                                                                                           
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const; //Converts the fixed point value to a floating point value
        int toInt( void ) const; //Converts the fixed point value to an integer value
 };

//An overload of the insertion («) operator that inserts a floating-point representation
//of the fixed-point number into the output stream object passed as parameter.
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif

/*
Перегрузка оператора: В C++ вы можете перегружать операторы, чтобы изменить их поведение для пользовательских типов. 
В данном случае оператор << перегружен для работы с объектами класса Fixed.
Параметры функции:
std::ostream &out: Это ссылка на объект потока вывода (например, std::cout), в который будет записываться информация.
const Fixed &fixed: Это константная ссылка на объект класса Fixed, который мы хотим вывести.
out << fixed.toFloat();: Здесь вызывается метод toFloat() объекта fixed, который, предположительно, возвращает значение типа float. 
Это значение затем записывается в поток out.
return out;: Функция возвращает ссылку на поток out. Это позволяет использовать оператор << в цепочках, например: std::cout << obj1 << obj2;.
Зачем это нужно
Удобство вывода: Перегрузка оператора << позволяет удобно выводить объекты класса Fixed в стандартные потоки вывода, как если бы это были встроенные типы (например, int или float). Это делает код более читаемым и удобным.
Инкапсуляция логики вывода: Вместо того чтобы каждый раз вручную вызывать метод для получения значения, вы можете просто использовать оператор <<, что упрощает код и делает его более интуитивным.
Поддержка цепочек операций: Возвращая поток out, вы можете легко комбинировать несколько операций вывода в одну строку, 
что улучшает читаемость и сокращает количество строк кода.
if we don't create this overloading operator, we can't display Fixed Numbers (from class Fixed)
*/