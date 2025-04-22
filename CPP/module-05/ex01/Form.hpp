#pragma once 

#include <stdexcept>
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			signgrade;
		const int			execgrade;
		bool				issigned;
	public:
		Form(void);
		Form(const std::string name, const int signgrade, int execgrade);
		Form(const Form &src);
		~Form(void);
		std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		void beSigned(Bureaucrat &b);
		Form &operator=(const Form &cpy);

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

std::ostream &operator << (std::ostream &out, const Form &Form);

