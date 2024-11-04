#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17); //стек= 5 17
    std::cout << mstack.top() << std::endl; //17
    mstack.pop(); //убрали 17
    std::cout << mstack.size() << std::endl; //осталась 5, размер=1
    mstack.push(3); //добавили 3
    mstack.push(5); //добавили 5
    mstack.push(737); //добавили 737
    //[...]
    mstack.push(0); //добавили 0 итого стек= 5 3 5 737 0
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "MutantStack" << std::endl;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl;
    std::list<int> myList;
    myList.push_back(5);
    myList.push_back(17);
    std::cout << myList.back() << std::endl;
	myList.pop_back();
	std::cout << myList.size() << std::endl;
    myList.push_back(3);
    myList.push_back(5);
    myList.push_back(737);
    myList.push_back(0);
    std::list<int>::iterator itList = myList.begin();
    std::list<int>::iterator iteList = myList.end();
    ++itList;
    --itList;
    std::cout << "List" << std::endl;
    while (itList != iteList)
    {
        std::cout << *itList << " " ;
        ++itList;
    }
    std::cout << std::endl;

    MutantStack<char> arr1;
    arr1.push('a');
    arr1.push('b');
    arr1.push('c');
    arr1.push('d');
    arr1.push('e');
    MutantStack<char>::iterator it1 = arr1.begin();
    MutantStack<char>::iterator ite1 = arr1.end();
    std::cout << "MutantStack arr" << std::endl;
    while (it1 != ite1)
    {
        std::cout << *it1 << " ";
        ++it1;
    }
    std::cout << std::endl;

    return 0;
}
