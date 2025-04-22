#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
	const std::string	name;
		int					grade;
		public:
		Bureaucrat(void);
		Bureaucrat(std::string Name, int Grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);
		Bureaucrat &operator= (const Bureaucrat &cpy);

		void increase(void);
		void decrease(void);
		std::string getName(void) const;
		int getGrade(void) const;
		void signForm(AForm &form);
		void executeForm(AForm const &form);

		class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
		};
};

std::ostream &operator << (std::ostream &out, const Bureaucrat &Bureaucrat);
