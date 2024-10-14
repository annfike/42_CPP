#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm: public AForm
{
    public:
            RobotomyRequestForm();
            RobotomyRequestForm(const std::string target);
            RobotomyRequestForm(RobotomyRequestForm const &arg);
            RobotomyRequestForm& operator=(RobotomyRequestForm const &arg);
            virtual ~RobotomyRequestForm();
            
            void execute(Bureaucrat const &executor) const;
};
#endif

