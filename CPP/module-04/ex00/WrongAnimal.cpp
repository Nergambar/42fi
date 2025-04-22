#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default wrong constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "Parametric Wrong constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrong)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = wrong;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator = (const WrongAnimal &src)
{
	if (this != &src)
	{
		std::cout << " -> Copy assignement WrongAnimal called." << std::endl;
		type = src.type;
	}
	return *this;
}
std::string	WrongAnimal::getType(void) const
{
	return type;
}
void	WrongAnimal::makeSound() const
{
	std::cout << "BEEEEEEEEEEEEEEEEEEEEEEEEE im a cow..." << std::endl;
}