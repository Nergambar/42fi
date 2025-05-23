#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Default"), grade(10)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string Name, int Grade) : name(Name), grade(Grade)
{
    if (Grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (Grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Parametric Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat default destructor called" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
    return (name);
}

int Bureaucrat::getGrade(void) const
{
    return (grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return("grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return("grade too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat's grade " << b.getGrade() << std::endl;
    return (out);
}

void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
	}
	catch(std::exception &e)
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
	(void)cpy;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	return(*this);
}


void Bureaucrat::increase()
{
    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrease()
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}
