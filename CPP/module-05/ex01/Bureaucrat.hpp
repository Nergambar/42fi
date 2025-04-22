#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

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

		void increase(void);
		void decrease(void);
		std::string getName(void) const;
		int getGrade(void) const;
		void signForm(Form &form);


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
