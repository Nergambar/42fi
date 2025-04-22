#pragma once 

#include <stdexcept>
#include <string>
#include <iostream>
#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
	private:
		const std::string	name;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string name);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);
		~RobotomyRequestForm(void);
		void execute(Bureaucrat const &src) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator << (std::ostream &out, const RobotomyRequestForm &RobotomyRequestForm);