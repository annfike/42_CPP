#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer Default constructor called" << std::endl;
}

Serializer::Serializer(Serializer const &arg)
{
    std::cout << "Serializer copy constructor called" << std::endl;
    *this = arg;
}

Serializer& Serializer::operator=(Serializer const &arg)
{
    std::cout << "Serializer assignation operator called" << std::endl;
    if (this != &arg){
        return *this;
    }
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor called" << std::endl;
}

//--------------------------------------------------------------------

uintptr_t Serializer::serialize(Data* ptr)
{
    std::cout << "Serializer serialize called" << std::endl;
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    std::cout << "Serializer deserialize called" << std::endl;
    return reinterpret_cast<Data*>(raw);
}
