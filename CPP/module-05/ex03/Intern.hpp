#ifndef INTERN_HPP
#define INTERN_HPP

#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Bureaucrat;


class Intern
{
	public:
		AForm *makeForm(std::string formname, std::string target);
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &intern);
};

#endif