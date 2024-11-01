#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

class Serializer
{
    private:
        Serializer();
        Serializer(Serializer const &arg);
        Serializer& operator=(Serializer const &arg);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif

/*
uintptr_t: Это тип данных, который гарантированно может хранить указатель в виде целого числа. 
Он используется для безопасного преобразования указателей в целые числа и обратно.

reinterpret_cast<uintptr_t>(ptr): Здесь указатель ptr преобразуется в тип uintptr_t. 
Это позволяет сохранить адрес объекта Data в виде целого числа. 
reinterpret_cast используется для низкоуровневого преобразования типов, и в данном случае это безопасно, 
так как мы просто преобразуем указатель в целое число.

reinterpret_cast<Data*>(raw): Здесь целое число raw преобразуется обратно в указатель на объект типа Data. 
Это позволяет восстановить указатель на объект, который был сериализован ранее.
*/