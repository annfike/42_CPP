#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) 
{
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) 
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}


Bureaucrat::Bureaucrat(Bureaucrat const &arg)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = arg;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &arg)
{
    std::cout << "Bureaucrat assignation operator called" << std::endl;
    if (this != &arg){
        this->grade = arg.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string const Bureaucrat::getName() const{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::increaseGrade()
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decreaseGrade()
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream &cout, Bureaucrat const &src)
{
    cout << src.getName() << ", Bureaucrat grade " << src.getGrade();
    return cout;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signs " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
    