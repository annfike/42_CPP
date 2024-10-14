#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, "default")
{
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5, target)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &arg) : AForm(arg)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = arg;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &arg)
{
    std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
    if (this != &arg)
    {
        AForm::operator=(arg);
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
