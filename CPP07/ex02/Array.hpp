#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(Array const &arg);
        ~Array();
        Array &operator=(Array const &arg);
        T &operator[](unsigned int i);
        unsigned int size() const;
        class OutOfRangeException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#include "Array.tpp"

#endif