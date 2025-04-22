#pragma once 

#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const int			signgrade;
		const int			execgrade;
		bool				issigned;
	public:
		AForm(void);
		AForm(const std::string name, const int signgrade, int execgrade);
		AForm(const AForm &src);
		virtual ~AForm(void);
		std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getSign(void) const;
		virtual void beSigned(Bureaucrat &b);
		AForm &operator=(const AForm &cpy);
        virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream &operator << (std::ostream &out, const AForm &AForm);

