#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <sstream>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::vector<int> _S;
        std::vector<int> _L;
        std::deque<int> _deque;
        std::deque<int> _S_deque;
        std::deque<int> _L_deque;

    public:
        PmergeMe();
        PmergeMe(PmergeMe const &src);
        ~PmergeMe();
        PmergeMe &operator=(PmergeMe const &src);

        void mergeMe(int argc, char **argv);
        bool parse_input(int argc, char **argv);
        void create_S_L(std::vector<std::pair<int, int> >& pairs);
        void create_S_L_deque(std::deque<std::pair<int, int> >& pairs);
        void sort_vector(std::vector<int> &vec);
        void sort_deque(std::deque<int> &deq);
        
        template <typename T>
        void display_container(T &container);
   
};

#endif



/*
https://en.wikipedia.org/wiki/Merge-insertion_sort
https://ru.wikipedia.org/wiki/Двоичный_поиск
https://ru.wikipedia.org/wiki/Числа_Якобсталя

Алгоритм -> вектор {5, 2, 4, 17, 3, 7, 6, 1} ./PmergeMe 5 2 4 17 3 7 6 1
1. Разделение на пары {5, 2}, {4, 17}, {3, 7}, {6, 1}
2. Сортировка чисел внутри каждой пары {5, 2}, {17, 4}, {7, 3}, {6, 1}
3. Рекурсивная сортировка и слияние пар {5, 2}, {6, 1}, {7, 3}, {17, 4}
4. Создание последовательности S из первых элементов пар и последовательности L из вторых элементов пар.
S = {5, 6, 7, 17}
L = {2, 1, 3, 4}
Вставляем первый элемент из L в начало S.
S = {2, 5, 6, 7, 17}
L = {2, 1, 3, 4}
5. Бинарный поиск, используя числа Якобсталя


Числа Якобсталя определяются следующим образом:
J(0)=0
J(1)=1
Для n≥2:
J(n)=J(n−1)+J(n−2)*2
0 1 1 3 5 11 21 43 85 171 341 683...

Почему это работает быстрее для std::vector, чем для std::deque?
Доступ к элементам:
std::vector предоставляет константное время для доступа к элементам по индексу 
В std::deque доступ по индексу тоже возможен, но на самом деле работает медленнее, 
так как deque реализован как набор блоков памяти. Это приводит к большему времени для вычисления индекса 
и доступа к данным, так как каждый доступ может требовать пересчета смещения блоков памяти.
Вставка элементов:
так как vector в памяти располагается как непрерывный блок, эти операции работают быстрее в сравнении с 
std::deque, который может требовать больше операций для перемещения блоков памяти при вставке.
Динамическое расширение:
std::vector может эффективно расширяться, перераспределяя память, что позволяет операции вставки и удаления 
работать быстрее на больших объемах данных. 
В deque расширение блоков памяти может требовать более сложных операций, что делает вставку медленнее.
Таким образом, хотя std::deque может быть эффективен для некоторых операций (например, вставка в начало или конец), 
для операций, связанных с произвольным доступом и вставкой в середину, std::vector работает быстрее из-за своей непрерывной структуры памяти.

*/