#include "Span.hpp"

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try{
        sp.addNumber(14);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "-------------Array: ";
    // Печать содержимого вектора без объявления функции печати внутри класса
    const std::vector<int>& nums = sp.getNumbers(); // Получаем вектор
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << " "; // Печатаем элементы
    }
    std::cout << std::endl;

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: "  << sp.longestSpan() << std::endl;

    Span sp1 = Span(20000);
    for (int i = 0; i < 20000; i++)
    {
        sp1.addNumber(i);
    }
    std::cout << "-------------Array 0-20000 " << std::endl;
    std::cout << "Shortest Span: " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest Span: "  << sp1.longestSpan() << std::endl;

    Span sp2(9);
    std::vector<int> v(7, 12);
    std::vector<int> v1(2, 1);

    try
    {
        sp2.addNumbers(v.begin(), v.end());
        sp2.addNumbers(v1.begin(), v1.end());
    }
    catch (Span::SpanFullException &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------Array: ";
    // Печать содержимого вектора без объявления функции печати внутри класса
    const std::vector<int>& nums2 = sp2.getNumbers(); // Получаем вектор
    for (size_t i = 0; i < nums2.size(); ++i) {
        std::cout << nums2[i] << " "; // Печатаем элементы
    }
    std::cout << std::endl;
       

    return 0;
}