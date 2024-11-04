#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {}
        MutantStack(const MutantStack &arg) : std::stack<T>(arg) {}
        MutantStack &operator=(const MutantStack &arg) {std::stack<T>::operator=(arg); return *this;}
        ~MutantStack() {}

        typedef typename std::stack<T>::container_type::iterator iterator; //Определяется тип iterator, который является итератором контейнера, используемого в стандартном стеке. container_type — это внутренний тип контейнера, на котором основан стек (обычно это std::deque).

        iterator begin(){
            return std::stack<T>::c.begin(); // к объекту container_type std::stack<T> можно получить доступ с помощью c(лежит в protected)
        };

        iterator end(){
            return std::stack<T>::c.end();
        };
};

#endif
