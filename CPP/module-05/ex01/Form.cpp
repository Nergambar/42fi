#include "Form.hpp"

Form::Form() : name("default"), signgrade(150), execgrade(150), issigned(false)
{
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(const std::string name, int signgrade, int execgrade) : name(name), signgrade(signgrade), execgrade(execgrade), issigned(false)
{
	if (signgrade < 1 || execgrade < 1)
		throw(GradeTooHighException());
	else if (signgrade > 150 || execgrade > 150)
		throw(GradeTooLowException());
	std::cout << "form constructor called" << std::endl;
}

Form::Form(const Form &src): name(src.name), signgrade(src.signgrade), execgrade(src.execgrade), issigned(src.issigned)
{
	std::cout << "Form copy constructor called";
}

Form::~Form(void)
{
	std::cout << "Form default destructor called" << std::endl;
}

Form &Form::operator=(const Form &cpy)
{
	if (this != &cpy)
		this->issigned = cpy.issigned;
	std::cout << "form copy constructor called" << std::endl;
	return(*this);
}

std::string Form::getName(void) const
{
	return (this->name);
}

int Form::getSignGrade(void) const
{
	return (this->signgrade);
}

int Form::getExecGrade(void) const
{
	return (this->execgrade);
}

void Form::beSigned(Bureaucrat &b)
{
	if (issigned == true)
	{
		std::cout << "form already signed" << std::endl;
		return;
	}
	if (b.getGrade() > this->signgrade)
		throw Bureaucrat::GradeTooLowException();
	issigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &b)
{
    out << b.getName() << "'s form got the grade necessary to be signed: " << b.getSignGrade() << std::endl;
    return (out);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return("grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return("grade too low");
}