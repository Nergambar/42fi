#pragma once 

#include <stdexcept>
#include <string>
#include <iostream>
#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
	private:
		const std::string	name;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string name, const int signgrade, int execgrade);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string name);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &cpy);
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

std::ostream &operator << (std::ostream &out, const PresidentialPardonForm &PresidentialPardonForm);