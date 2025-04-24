#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
#include "AForm.hpp"

#define RESETTEXT "\033[0m"
#define FOREBLK "\033[30m"
#define FORERED "\033[31m"
#define FOREGRN "\033[32m"
#define FOREYEL "\033[33m"
#define FOREBLU "\033[34m"
#define FOREMAG "\033[35m"
#define FORECYN "\033[36m"
#define FOREWHT "\033[37m"

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
