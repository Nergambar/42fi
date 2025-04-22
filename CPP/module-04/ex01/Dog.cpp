#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default Dog Constructor called" << std::endl;
	brain  = new Brain;
}

Dog::~Dog()
{
	std::cout << "Default Dog Destructor called" << std::endl;
	delete brain;
}

Dog  &Dog::operator = (const Dog &dog)
{
    std::cout << "Dog copy operator called" << std::endl;
    if (this != &dog)
    {
        Animal::operator=(dog);
        this->type = dog.type;
        brain = new Brain(*dog.brain);
    }
    return (*this);
}

Dog::Dog(const Dog &doggo) : Animal(doggo.type)
{
	type = doggo.getType();
	brain = new Brain(*doggo.brain);
	std::cout << "Dog Copy Constructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "BAO SO UN CANE, UMME CREDI?" << std::endl;
}

std::string Dog::getIdeas(int i) const
{
	return (brain->getIdea(i));
}

void Dog::changeIdeas(std::string idea, int i)
{
	brain->setIdea(idea, i);
}