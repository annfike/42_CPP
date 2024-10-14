#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("default"), sign(false), gradeToSign(150), gradeToExecute(150) 
{
    std::cout << "Form Default constructor called" << std::endl;
}


Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) 
{
    std::cout << "Form constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    
}

Form::Form(Form const &arg) : name(arg.name), sign(arg.sign), gradeToSign(arg.gradeToSign), gradeToExecute(arg.gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;    
    *this = arg;
}

Form& Form::operator=(Form const &arg)
{
    std::cout << "Form assignation operator called" << std::endl;
    if (this != &arg){
        this->sign = arg.sign;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string const Form::getName() const
{
    return name;
}

bool Form::getSign() const
{
    return sign;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    this->sign = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream &cout, Form const &src)
{
    cout << src.getName() << ", Form sign " << src.getSign() << ", grade to sign " << src.getGradeToSign() << ", grade to execute " << src.getGradeToExecute();
    return cout;
}



