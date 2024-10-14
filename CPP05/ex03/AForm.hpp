#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
            std::string const name;
            bool			sign;
            int const	gradeToSign;
            int const	gradeToExecute;
            std::string target;
    public:
            AForm();
            AForm(const std::string name, int gradeToSign, int gradeToExecute, std::string target);
            AForm(AForm const &arg);
            AForm& operator=(AForm const &arg);
            virtual ~AForm();
            
            std::string const getName() const;
            bool getSign() const;
            int getGradeToSign() const;
            int getGradeToExecute() const;
            std::string getTarget() const;

            void beSigned(Bureaucrat &bureaucrat);
            virtual void execute(Bureaucrat const &executor) const = 0;

            //Обработка исключений - исключительных ситуаций в работе программы
            //std::exception - базовый клас с++ обрабатывающий исключения
            //Все классы обработки исключений создаются путем наследования его
            class GradeTooHighException: public std::exception{
                public:
                        virtual const char *what() const throw();
            };
            class GradeTooLowException: public std::exception{
                public:
                        virtual const char *what() const throw();
            };
            class FormNotSignedException: public std::exception{
                public:
                        virtual const char *what() const throw();
            };

};

std::ostream& operator<<(std::ostream &cout, AForm const &src);





#endif