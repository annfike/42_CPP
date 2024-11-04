#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <numeric>

class Span
{
    private:
        std::vector<int> array;
        unsigned int max_elements;
    public:
        Span();
        Span(unsigned int n);
        Span(Span const &arg);
        Span &operator=(Span const &arg);
        ~Span();

        void addNumber(int n);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        class SpanEmptyException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class SpanFullException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        const std::vector<int>& getNumbers() const {
            return array; // Возвращаем ссылку на вектор (для печати в мэйне)
    }
};

#endif
