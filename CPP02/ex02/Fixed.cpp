#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = value << number_of_bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * (1 << number_of_bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Assignation operator called" << std::endl;
    value = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)value / (1 << number_of_bits);
}

int Fixed::toInt(void) const
{
    return value >> number_of_bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed result;

    result.setRawBits(value + fixed.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed result;

    result.setRawBits(value - fixed.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    Fixed result;

    result.setRawBits((value * fixed.getRawBits()) >> number_of_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    Fixed result;

    result.setRawBits((value << number_of_bits) / fixed.getRawBits());
    return result;
}

Fixed &Fixed::operator++()
{
    value++;
    return *this; 
    /*Метод возвращает ссылку на текущий объект (*this), что позволяет использовать его в цепочках операций. 
    Например, можно писать ++obj;, и это будет возвращать тот же объект с обновленным значением.*/
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this); //Создается временный объект tmp, который инициализируется текущим объектом (*this). Это позволяет сохранить исходное значение объекта до увеличения

    operator++();//Здесь вызывается метод префиксного инкремента, который увеличивает значение value текущего объекта. Это позволяет избежать дублирования кода, так как логика инкремента уже реализована в префиксном методе.
    return tmp; //Возвращается временный объект tmp, который содержит исходное значение value до увеличения. Это позволяет возвращать значение до инкремента, что может быть полезно в некоторых случаях.
}

Fixed &Fixed::operator--()
{
    value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);

    operator--();
    return tmp;
}

/*выбор между этими двумя версиями функции min зависит от того, хотите ли вы, чтобы возвращаемый объект мог быть изменен (первая версия) или не мог (вторая версия). 
Это позволяет разработчикам выбирать подходящий вариант в зависимости от контекста использования.*/

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    return a > b ? a : b;
}




