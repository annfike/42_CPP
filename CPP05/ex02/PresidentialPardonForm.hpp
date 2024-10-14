#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <stdlib.h>

class PresidentialPardonForm: public AForm
{
    public:
            PresidentialPardonForm();
            PresidentialPardonForm(const std::string target);
            PresidentialPardonForm(PresidentialPardonForm const &arg);
            PresidentialPardonForm& operator=(PresidentialPardonForm const &arg);
            virtual ~PresidentialPardonForm();
            
            void execute(Bureaucrat const &executor) const;
};

#endif