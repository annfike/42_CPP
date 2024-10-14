#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(Intern const &arg)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = arg;
}

Intern& Intern::operator=(Intern const &arg)
{
    std::cout << "Intern assignation operator called" << std::endl;
    (void)arg;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

static AForm *makeShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm *makeRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *makePresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    AForm *form = NULL;
    std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm *(*createForm[])(std::string) = {makeShrubberyCreationForm, makeRobotomyRequestForm, makePresidentialPardonForm};
    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
        {
            form = createForm[i](target);
            std::cout << "Intern creates " << name << std::endl;
        }
    }
    if (!form)
        throw Intern::FormNotFoundException();
    return form;
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}

