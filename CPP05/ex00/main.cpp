#include "Bureaucrat.hpp"

int main(){
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);
    Bureaucrat b3("b3", 75);


    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;

    try{
        b1.increaseGrade();
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        b2.decreaseGrade();
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        b3.increaseGrade();
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << b3 << std::endl;

}