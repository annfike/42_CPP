#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("default"), sign(false), gradeToSign(150), gradeToExecute(150), target("default")
{
    std::cout << "AForm Default constructor called" << std::endl;
}


AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute, std::string target) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target)
{
    std::cout << "AForm constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    
}

AForm::AForm(AForm const &arg) : name(arg.name), sign(arg.sign), gradeToSign(arg.gradeToSign), gradeToExecute(arg.gradeToExecute), target(arg.target)
{
    std::cout << "AForm copy constructor called" << std::endl;    
    *this = arg;
}

AForm& AForm::operator=(AForm const &arg)
{
    std::cout << "AForm assignation operator called" << std::endl;
    if (this != &arg){
        this->sign = arg.sign;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

std::string const AForm::getName() const
{
    return name;
}

bool AForm::getSign() const
{
    return sign;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    this->sign = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream &cout, AForm const &src)
{
    cout << src.getTarget() << ", " << src.getName() << ", sign=" << src.getSign() << ", grade to sign=" << src.getGradeToSign() << ", grade to execute=" << src.getGradeToExecute();
    return cout;
}

void AForm::execute(Bureaucrat const &executor) const
{
    //std::cout << executor.getName() << " is executing " << this->getName() << std::endl;
    if (executor.getGrade() > this->gradeToExecute)
        throw AForm::GradeTooLowException();
    if (!this->sign)
        throw AForm::FormNotSignedException();    
}

std::string	AForm::getTarget(void) const
{
	return (this->target);
}


