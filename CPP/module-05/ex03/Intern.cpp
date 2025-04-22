#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	(void)src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern default destructor called" << std::endl;
}

Intern &Intern::operator = (const Intern &copy)
{
	if (this != &copy)
		std::cout << "Intern copy operator called" << std::endl;
	return (*this);
}

AForm *Intern::makeForm(std::string formname, std::string target)
{
	std::string array[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	int index = 0;
	while (index < 3)
	{
		if (array[index] == formname)
			break ;
		index++;
	}
	switch(index) {
		case (0):
		{
			std::cout << "\033[35m" << "Intern creates " << formname << "\033[0m" << std::endl;
			return (new RobotomyRequestForm(target));
		}
		case (1):
		{
			std::cout << "\033[35m"  << "Intern creates " << formname << "\033[0m" << std::endl;
			return (new ShrubberyCreationForm(target));
		}
		case (2):
		{
			std::cout << "\033[35m"  << "Intern creates " << formname << "\033[0m" << std::endl;
			return (new PresidentialPardonForm(target));
		}
		default:
		{
			std::cout << "\033[31m" << "Unknown type" << "\033[0m" << std::endl;
			return (NULL);
		}
	}
}