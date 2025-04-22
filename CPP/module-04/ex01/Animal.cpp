#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	type = animal.getType();
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Parametric Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Default destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "..." << std::endl;
}

std::string Animal::getType() const
{
	return(type);
}

Animal &Animal::operator = (const Animal &animal)
{
	std::cout << "animal copy operator called" << std::endl;
	if (this != &animal)
	{
		type = animal.getType();
	}
	return (*this);
}