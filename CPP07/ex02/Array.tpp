#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array const &arg) : array(new T[arg._size]), _size(arg._size)
{
    for (unsigned int i = 0; i < _size; i++)
    {
        array[i] = arg.array[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &arg)
{
    if (this != &arg)
    {
        delete[] array;
        array = new T[arg._size];
        _size = arg._size;
        for (unsigned int i = 0; i < _size; i++)
        {
            array[i] = arg.array[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
    {
        throw OutOfRangeException();
    }
    return array[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw()
{
    return "Out of range";
}


/*
Файл с расширением .tpp (или .hpp, но .tpp используется чаще для реализации шаблонов) 
обычно содержит реализации шаблонных классов и функций.

Содержимое: В этих файлах размещаются реализации шаблонов, которые не могут быть инстанциированы (созданы) 
до тех пор, пока не станет известен конкретный тип, с которым они будут использоваться. 
Это позволяет избежать проблем с компиляцией, так как шаблоны могут быть объявлены в .hpp или .h файлах, 
а их реализации — в .tpp файлах.

Использование: .tpp файлы часто подключаются в .hpp файлы, чтобы компилятор мог видеть реализации шаблонов, 
когда он их инстанциирует в других .cpp файлах.
*/