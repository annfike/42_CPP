#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat b1("b1", 1);
        Bureaucrat b2("b2", 150);
        ShrubberyCreationForm f1("f1");
        ShrubberyCreationForm f2("f2");
        RobotomyRequestForm f3("f3");
        RobotomyRequestForm f4("f4");
        PresidentialPardonForm f5("f5");
        PresidentialPardonForm f6("f6");

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;
        std::cout << f4 << std::endl;
        std::cout << f5 << std::endl;
        std::cout << f6 << std::endl;

        std::cout << "------ShrubberyCreationForm-------" << std::endl;
        b1.signForm(f1);
        b1.executeForm(f1);
        b2.signForm(f2);
        b2.executeForm(f2);
        b1.executeForm(f2);

        std::cout << "------RobotomyRequestForm-------" << std::endl;
        b1.signForm(f3);
        b1.executeForm(f3);
        b2.signForm(f4);
        b2.executeForm(f4);
        b1.executeForm(f4);
        b1.signForm(f4);
        b1.executeForm(f4);

        std::cout << "------PresidentialPardonForm-------" << std::endl;
        b1.signForm(f5);
        b1.executeForm(f5);
        b2.signForm(f6);
        b2.executeForm(f6);
        b1.executeForm(f6);
        b1.signForm(f6);
        b1.executeForm(f6);
 
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;

    

}