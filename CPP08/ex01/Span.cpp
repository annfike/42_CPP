#include "Span.hpp"

Span::Span() : max_elements(0)
{}

Span::Span(unsigned int n) : max_elements(n)
{}

Span::Span(Span const &arg)
{
    *this = arg;
}

Span &Span::operator=(Span const &arg)
{
    this->array = arg.array;
    this->max_elements = arg.max_elements;
    return *this;
}

Span::~Span()
{}

void Span::addNumber(int n)
{
    if (this->array.size() >= this->max_elements)
        throw SpanFullException();
    this->array.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->array.size() + std::distance(begin, end) > this->max_elements) // distance - количество элементов в диапазоне, заданном итераторами
        throw SpanFullException();
    this->array.insert(this->array.end(), begin, end);
}

unsigned int Span::shortestSpan()
{
    if (this->array.size() <= 1)
        throw SpanEmptyException();
    std::vector<int> sorted_array = this->array;
    std::sort(sorted_array.begin(), sorted_array.end());
    std::adjacent_difference(sorted_array.begin(), sorted_array.end(), sorted_array.begin()); //ычисляет разности между соседними элементами массива и сохраняет результат обратно в sorted_array. Таким образом, первый элемент будет равен нулю.
    unsigned int shortest = *std::min_element(sorted_array.begin() + 1, sorted_array.end()); // Находится минимальный элемент в массиве, начиная с второго элемента (первый элемент — это ноль). 
    return shortest;
}

unsigned int Span::longestSpan()
{
    if (this->array.size() <= 1)
        throw SpanEmptyException();
    std::vector<int> sorted_array = this->array;
    std::sort(sorted_array.begin(), sorted_array.end());
    return sorted_array[sorted_array.size() - 1] - sorted_array[0]; // Возвращается разность между последним и первым элементами отсортированного массива, что и есть наибольший промежуток.
}

const char *Span::SpanEmptyException::what() const throw()
{
    return "Span not found";
}

const char *Span::SpanFullException::what() const throw()
{
    return "Array is full";
}

