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
    std::cout << "Parametric Bureaucrat Constructor called" << RESETTEXT << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat default destructor called" << RESETTEXT << std::endl;
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

void Bureaucrat::signForm(AForm &form)
{
	try {
		form.beSigned(*this);
		std::cout << FORECYN << this->name << " signed " << form.getName() << RESETTEXT << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << FOREBLK << this->getName() << " executed " << form.getName() << RESETTEXT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << FOREGRN << this->getName() << " couldn't execute " << form.getName() << " because " << RESETTEXT;
		std::cerr << e.what() << '\n';
	}
	
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

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return("grade too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat's grade " << b.getGrade() << std::endl;
    return (out);
}