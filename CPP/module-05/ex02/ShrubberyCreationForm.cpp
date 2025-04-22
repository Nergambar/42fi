#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("def", 145, 137), name("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src), name(src.name)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : AForm("ShrubberyForm", 145, 137), name(name)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &exec) const
{
	if (this->getSign() == false)
	{
		std::cout << "Form not signed" << std::endl;
		return;
	}
	if (exec.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::ofstream file((name + "_shrubbery").c_str());
	if (!file)
		throw(ShrubberyCreationForm::FileNotOpened());
	file << "		1		" << std::endl;
	file << "      111      " << std::endl;
	file << "     11111     " << std::endl;
	file << "    1111111    " << std::endl;
	file << "   111111111   " << std::endl;
	file << "  11111111111  " << std::endl;
	file << " 1111111111111 " << std::endl;
	file << "111111111111111" << std::endl;
	file << "     |   |     " << std::endl;
	file << "     |   |     " << std::endl;
	file << "     |   |     " << std::endl;
	file << "     |   |     " << std::endl;
	file.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	if (this != &cpy)
	{
		this->AForm::operator=(cpy);
	}
	return *this;
}

const char *ShrubberyCreationForm::FileNotOpened::what() const throw()
{
	return("can't open file");
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default destructor called" << std::endl;
}