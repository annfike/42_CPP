#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
            std::string const name;
            bool			sign;
            int const	gradeToSign;
            int const	gradeToExecute;
    public:
            Form();
            Form(const std::string name, int gradeToSign, int gradeToExecute);
            Form(Form const &arg);
            Form& operator=(Form const &arg);
            ~Form();
            
            std::string const getName() const;
            bool getSign() const;
            int getGradeToSign() const;
            int getGradeToExecute() const;

            void beSigned(Bureaucrat &bureaucrat);
            
            class GradeTooHighException: public std::exception{
                public:
                        virtual const char *what() const throw();
            };
            class GradeTooLowException: public std::exception{
                public:
                        virtual const char *what() const throw();
            };

};

std::ostream& operator<<(std::ostream &cout, Form const &src);





#endif