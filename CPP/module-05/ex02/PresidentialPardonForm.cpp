#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("name", 25, 5), name("name")
{
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm copy operator called" << std::endl;
	if (this != &copy)
	{
		this->AForm::operator=(copy);
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &src) const
{
	if (this->getSign() ==  false)
		std::cout << "Form not signed" << std::endl;
	if (src.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << name << "has been pardoned by Zaphod Beeblebrox";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm(src), name(src.name)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name) : AForm("PresidentialPardonForm", 25, 5), name(name)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}