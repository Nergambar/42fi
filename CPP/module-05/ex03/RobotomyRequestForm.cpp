#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("name", 72, 45), name("name")
{
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm copy operator called" << std::endl;
	if (this != &copy)
	{
		this->AForm::operator=(copy);
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), name(src.name)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name) : AForm("RobotomyRequestForm", 72, 45), name(name)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &src) const
{
	if (this->getSign() ==  false)
		std::cout << "Form not signed" << std::endl;
	if (src.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << "brrrr bzzzz trrrrr prrrrr drill noises drill noises..." << std::endl;
	if (rand() % 2 == 0)
		std::cout << name << " has been robotomized" << std::endl;
	else
		std::cout << name << "'s robotomization has failed" << std::endl;
}


RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}