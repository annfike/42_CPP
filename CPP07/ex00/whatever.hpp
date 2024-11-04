#ifndef WHATEVER_HPP
#define WHATEVER_HPP

//https://metanit.com/cpp/tutorial/9.2.php

#include <iostream>


template <typename T>
void swap(T &a, T &b) // Функция принимает два аргумента a и b по ссылке (&). Это означает, что функция работает с оригинальными переменными, а не с их копиями. Изменения, произведенные с a и b, будут отражены на исходных переменных, переданных в функцию.
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T a, T b)
{
    return a < b ? a : b;
}

template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

#endif

/*
Шаблоны классов позволяют определить конструкции (функции, классы), которые используют определенные типы, 
но на момент написания кода точно не известно, что это будут за типы. 
Иными словами, шаблоны позволяют определить универсальные конструкции, которые не зависят от определенного типа.

template<typename T> T add(T a, T b)
В данном случае после typename указан один параметр - T. Параметр шаблона представляет произвольный идентификатор, в качестве которого, 
как правило, применяются заглавные буквы, например, T. Но это необязательно. 
То есть в данном случае параметр T будет представлять некоторый тип, который становится известным во время компиляции. 
Это может быть и тип int, и double, и string, и любой другой тип. Но поскольку внутри функции мы применяем операцию сложения, 
важно, чтобы тип, который будет применяться вместо параметра T, поддерживал операцию сложения, которая возвращала бы объект этого же типа. 
Если вдруг используемый тип не будет применять операцию сложения, то на этапе компиляции мы столкнемся с ошибкой.

И при вызове функции add в нее можно передавать объекты и типа int, и типа double, и любого другого типа. 
При вызове функции компилятор на основании типа аргументов выведет конкретный тип, связанный с параметром шаблона T, 
и создаст экземпляр функции add, который работает с конкретным типом, и при вызове функции будет вызваться данный экземпляр функции. 
Если для последующего вызова функции требуется тот же экземпляр, то компилятор использует существующий экземпляр функции.

При этом также можно использовать ссылки, указатели, массивы, которые представляют тип параметра шаблона.
*/