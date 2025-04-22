#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Default Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &doggo) : Animal(doggo.type)
{
	type = doggo.getType();
	std::cout << "Dog Copy Constructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "BAO SO UN CANE, UMME CREDI?" << std::endl;
}