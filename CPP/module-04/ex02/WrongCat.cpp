#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrong)
{
    std::cout << "wrong copy constructor called" << std::endl;
    this->type = wrong.type;
}

WrongCat  &WrongCat::operator = (const WrongCat &wrongCat)
{
    std::cout << "WrongCat copy operator called" << std::endl;
    if (this != &wrongCat)
    {
        this->type = wrongCat.type;
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat default destructor called" << std::endl;
}


void WrongCat::makeSound() const
{
	std::cout << "I'll say it, I dont care that you broke your arm" << std::endl;
}