#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
			std::string const name;
			int			grade; // 1-150
	public:
			Bureaucrat();
            Bureaucrat(const std::string name, int grade);
			Bureaucrat(Bureaucrat const &arg);
			Bureaucrat& operator=(Bureaucrat const &arg);
            ~Bureaucrat();
			
			std::string const getName() const;
			int getGrade() const;

			void increaseGrade();// Since grade 1 is the highest one and 150 the lowest, incrementing a grade 3 should give a grade 2 to the bureaucrat.
			void decreaseGrade();
			class GradeTooHighException: public std::exception // GradeTooHighException наследуется от стандартного класса std::exception, что позволяет использовать его как исключение.
			{
				public:
						virtual const char *what() const throw();
			};
			class GradeTooLowException: public std::exception{
				public:
						virtual const char *what() const throw();
			};
};
std::ostream& operator<<(std::ostream &cout, Bureaucrat const &src);
//Перегрузка << оператора для ostream, который выводит <name>, Bureaucrat grade <grade>
#endif

/*virtual const char *what() const throw(); 
virtual — указывает, что метод может быть переопределен в производных классах.
const char *what() — объявление метода what, который возвращает указатель на строку символов (текстовое сообщение об ошибке).
const — означает, что метод не изменяет состояние объекта.
throw() — указывает, что метод не должен выбрасывать исключений (хотя в современных версиях C++ эта нотация считается устаревшей).
*/