#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Default Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat.type)
{
	type = cat.getType();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat  &Cat::operator = (const Cat &cat)
{
    std::cout << "Cat copy operator called" << std::endl;
    if (this != &cat)
    {
        Animal::operator=(cat);
        this->type = cat.type;
    }
    return (*this);
}

Cat::~Cat()
{
	std::cout << "Default cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MAO" << std::endl;
}