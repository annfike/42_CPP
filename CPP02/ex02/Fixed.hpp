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

        //Add public member functions to your class to overload the following operators:
        bool operator>(const Fixed &fixed) const;
        bool operator<(const Fixed &fixed) const;
        bool operator>=(const Fixed &fixed) const;
        bool operator<=(const Fixed &fixed) const;
        bool operator==(const Fixed &fixed) const;
        bool operator!=(const Fixed &fixed) const;

        Fixed operator+(const Fixed &fixed) const;
        Fixed operator-(const Fixed &fixed) const;
        Fixed operator*(const Fixed &fixed) const;
        Fixed operator/(const Fixed &fixed) const;

        Fixed &operator++(); //Pre-increment
        Fixed operator++(int); //Post-increment
        Fixed &operator--(); //Pre-decrement
        Fixed operator--(int); //Post-decrement
       
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed const &min(Fixed const &a, Fixed const &b);
                
        static Fixed &max(Fixed &a, Fixed &b);
        static Fixed const &max(Fixed const &a, Fixed const &b);

 };

//An overload of the insertion («) operator that inserts a floating-point representation
//of the fixed-point number into the output stream object passed as parameter.
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif