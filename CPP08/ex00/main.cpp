#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    std::list<int> l;
    std::deque<int> d;

    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
        l.push_back(i);
        d.push_back(i);
    }
    std::cout << "Vector: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "List: ";
    /* только в с11 
    for (int n : l)
        std::cout << n << "\t";
    std::cout << std::endl;*/
     for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " "; 
    }
    std::cout << std::endl;
    std::cout << "Deque: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;
    
    try{
        std::cout << "Vector: " << *easyfind(v, 3) << std::endl;
        std::cout << "Vector: " << *easyfind(v, 5) << std::endl;
        }
    catch (std::exception &e){
        std::cout << "Not found" << std::endl;}
     try{
        std::cout << "List: " << *easyfind(l, 0) << std::endl;
        std::cout << "List: " << *easyfind(l, 7) << std::endl;
        }
    catch (std::exception &e){
        std::cout << "Not found" << std::endl;}
     try{
        std::cout << "Deque: " << *easyfind(d, 3) << std::endl;
        std::cout << "Deque: " << *easyfind(d, 6) << std::endl;}
    catch (std::exception &e){
        std::cout << "Not found" << std::endl;}
   
    
    return 0;
}