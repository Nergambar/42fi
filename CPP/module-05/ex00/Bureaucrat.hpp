#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>
#include <iostream>

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
		
		std::string getName(void) const;
		int getGrade(void) const;
		void setGrade(int Grade);
		void increase();
		void decrease();



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

#endif