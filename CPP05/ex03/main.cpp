#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
        Bureaucrat b1("b1", 1);
        Bureaucrat b2("b2", 150);
        Intern intern;
        AForm *f1 = intern.makeForm("ShrubberyCreationForm", "f1");
        AForm *f2 = intern.makeForm("ShrubberyCreationForm", "f2");
        AForm *f3 = intern.makeForm("RobotomyRequestForm", "f3");
        AForm *f4 = intern.makeForm("RobotomyRequestForm", "f4");
        AForm *f5 = intern.makeForm("PresidentialPardonForm", "f5");
        AForm *f6 = intern.makeForm("PresidentialPardonForm", "f6");
        

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << *f1 << std::endl;
        std::cout << *f2 << std::endl;
        std::cout << *f3 << std::endl;
        std::cout << *f4 << std::endl;
        std::cout << *f5 << std::endl;
        std::cout << *f6 << std::endl;
        

        std::cout << "------ShrubberyCreationForm-------" << std::endl;
        b1.signForm(*f1);
        b1.executeForm(*f1);
        b2.signForm(*f2);
        b2.executeForm(*f2);
        b1.executeForm(*f2);

        std::cout << "------RobotomyRequestForm-------" << std::endl;
        b1.signForm(*f3);
        b1.executeForm(*f3);
        b2.signForm(*f4);
        b2.executeForm(*f4);
        b1.executeForm(*f4);
        b1.signForm(*f4);
        b1.executeForm(*f4);

        std::cout << "------PresidentialPardonForm-------" << std::endl;
        b1.signForm(*f5);
        b1.executeForm(*f5);
        b2.signForm(*f6);
        b2.executeForm(*f6);
        b1.executeForm(*f6);
        b1.signForm(*f6);
        b1.executeForm(*f6);

        delete f1;
        delete f2;
        delete f3;
        delete f4;
        delete f5;
        delete f6;
    
    try
    {
        AForm *f7 = intern.makeForm("WTF", "f7");
        std::cout << *f7 << std::endl;
        delete f7;
        Intern  someRandomIntern;
        AForm*   rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender"); 
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    
    return 0;

}