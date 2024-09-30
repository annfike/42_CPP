#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); // 10.1016
    std::cout << a << std::endl; // 0
    std::cout << ++a << std::endl; // 0.00390625
    std::cout << a << std::endl; // 0.00390625
    std::cout << a++ << std::endl; // Оператор a++ возвращает текущее значение a (то есть 0.00390625) перед его увеличением. 0.00390625
    std::cout << a << std::endl;    // После этой строки значение a увеличивается на 1/256, что делает его равным 0.0078125.т0.0078125
    std::cout << b << std::endl;   // 10.1016
    std::cout << Fixed::max( a, b ) << std::endl; // 10.1016
    std::cout << (a < b) << std::endl; // 1
    return 0;
}

/*
value = 1: После инкремента value равно 1.
Преобразование в float:
Если number_of_bits равно 8, то:
float result = static_cast<float>(1) / (1 << 8); // 1 / 256
Это дает 0.00390625.
*/
