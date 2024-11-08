#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>

/*
Пример вычисления выражений
Инфиксное выражение 
(1+2)×4+3 в ОПН может быть записано так: 1 2 + 4 × 3 +

Вычисление производится слева направо, ввод интерпретируется как указано в приведённой ниже таблице (указано состояние стека после выполнения операции, вершина стека справа):
Ввод	Операция	Стек
1	поместить в стек	1
2	поместить в стек	1, 2
+	сложение	3
4	поместить в стек	3, 4
*	умножение	12
3	поместить в стек	12, 3
+	сложение	15
*/

class RPN
{
    private:
        //std::string _input;

    public:
        RPN();
        RPN(RPN const &src);
        ~RPN();
        RPN &operator=(RPN const &src);

        void calculate(std::string input);


};

#endif