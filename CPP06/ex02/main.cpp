#include "Base.hpp"
#include <ctime>

Base * generate(void)
{
    std::srand(std::time(NULL));
    int random = std::rand() % 3;
    if (random == 0)
    {
        std::cout << "A instance generated" << std::endl;
        return new A;
    }
    else if (random == 1)
    {
        std::cout << "B instance generated" << std::endl;
        return new B;
    }
    else
    {
        std::cout << "C instance generated" << std::endl;
        return new C;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::exception &e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << "Unknown type1" << std::endl;
            }
        }
    }
}

int main()
{
    Base *base = generate();
    //Base *base = NULL; // nullptr will work in identify(base) but you can't use in identify(*base), only reference to existing object. But on my PC at home it works:D
    identify(base);
    identify(*base);
    D* d = new D;
    identify(d);
    identify(*d);
    delete base;
    delete d;
    return 0;
}

/*
Используйте void identify(Base* p):
Когда вы хотите иметь возможность передавать nullptr в функцию. 
Это может быть полезно, если вы хотите явно указать, что объект отсутствует.
Когда вам нужно работать с динамически выделенной памятью, и вы хотите иметь возможность проверять состояние указателя.

Используйте void identify(Base& p):
Когда вы уверены, что объект всегда будет действительным, и хотите избежать необходимости проверять на nullptr.
Когда вы хотите обеспечить более безопасный и чистый код, так как ссылки не могут быть nullptr и не требуют дополнительных проверок.
*/