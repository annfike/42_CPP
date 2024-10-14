#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, "default")
{
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45, target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &arg) : AForm(arg)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    *this = arg;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &arg)
{
    std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
    if (this != &arg){
        AForm::operator=(arg);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    //std::cout << rand() << std::endl;
    std::cout << getTarget() << ": Drr drr drr" << std::endl;
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomized" << std::endl;
    else
        std::cout << getTarget() << " failed to be robotomized" << std::endl;
}
