#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const &arg);
        Intern& operator=(Intern const &arg);
        ~Intern();
        AForm *makeForm(std::string name, std::string target);
        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif