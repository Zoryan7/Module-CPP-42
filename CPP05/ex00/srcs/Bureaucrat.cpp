#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
: _name("Default"), _grade(150)
{
    // std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) 
: _name(src._name), _grade(src._grade)
{
    // std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) 
{
    if (this->_grade < 1) 
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150) 
        throw Bureaucrat::GradeTooLowException();
    // std::cout << "Bureaucrat name constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() 
{
    // std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) 
{
    // std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &src) 
    {
        this->_grade = src._grade;
        if (this->_grade < 1) 
            throw Bureaucrat::GradeTooHighException();
        else if (this->_grade > 150) 
            throw Bureaucrat::GradeTooLowException();
    }
    return *this;
}

std::string Bureaucrat::getName() const 
{
    return (this->_name);
}

int Bureaucrat::getGrade() const 
{
    return (this->_grade);
}

void Bureaucrat::ft_increment_grade() 
{
    if (this->_grade <= 1) 
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::ft_decrement_grade() 
{
    if (this->_grade >= 150) 
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() 
{
    return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() 
{
    return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) 
{
    out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
    return (out);
}
