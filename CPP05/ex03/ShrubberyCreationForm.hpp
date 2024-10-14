#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
    public:
            ShrubberyCreationForm();
            ShrubberyCreationForm(const std::string target);
            ShrubberyCreationForm(ShrubberyCreationForm const &arg);
            ShrubberyCreationForm& operator=(ShrubberyCreationForm const &arg);
            virtual ~ShrubberyCreationForm();
            
            void execute(Bureaucrat const &executor) const;
};

#endif