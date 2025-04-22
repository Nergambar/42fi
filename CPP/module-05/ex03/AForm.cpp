#include "AForm.hpp"

AForm::AForm() : name("default"), signgrade(150), execgrade(150), issigned(false)
{
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, int signgrade, int execgrade) : name(name), signgrade(signgrade), execgrade(execgrade), issigned(false)
{
	if (signgrade < 1 || execgrade < 1)
		throw(GradeTooHighException());
	else if (signgrade > 150 || execgrade > 150)
		throw(GradeTooLowException());
	std::cout << "Aform constructor called" << std::endl;
}

AForm::AForm(const AForm &src): name(src.name), signgrade(src.signgrade), execgrade(src.execgrade), issigned(src.issigned)
{
	std::cout << "AForm copy constructor called";
}

AForm::~AForm(void)
{
	std::cout << "AForm default destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &cpy)
{
	if (this != &cpy)
		this->issigned = cpy.issigned;
	std::cout << "Aform copy constructor called" << std::endl;
	return(*this);
}

bool AForm::getSign() const
{
	return(this->issigned);
}

std::string AForm::getName(void) const
{
	return (this->name);
}

int AForm::getSignGrade(void) const
{
	return (this->signgrade);
}

int AForm::getExecGrade(void) const
{
	return (this->execgrade);
}

void AForm::beSigned(Bureaucrat &b)
{
	if (issigned == true)
	{
		std::cout << "Aform already signed" << std::endl;
		return;
	}
	if (b.getGrade() > this->signgrade)
		throw Bureaucrat::GradeTooLowException();
	issigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &b)
{
    out << b.getName() << "'s Aform got the grade necessary to be signed: " << b.getSignGrade() << std::endl;
    return (out);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return("grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return("grade too low");
}