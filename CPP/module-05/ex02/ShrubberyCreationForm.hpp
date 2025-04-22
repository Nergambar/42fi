#pragma once 

#include <stdexcept>
#include <string>
#include <iostream>
#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	name;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpy);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const &exec) const;
		ShrubberyCreationForm(const std::string name);
		class FileNotOpened : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator << (std::ostream &out, const ShrubberyCreationForm &ShrubberyCreationForm);