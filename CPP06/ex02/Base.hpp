#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
# include <string>
#include <stdlib.h>

//https://metanit.com/cpp/tutorial/5.26.php

class Base
{
    public:
        virtual ~Base();
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

class D: public Base 
{};
    
#endif