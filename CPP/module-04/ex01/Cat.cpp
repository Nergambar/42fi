#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Default Cat Constructor called" << std::endl;
	brain = new Brain;
}

Cat::Cat(const Cat &cat) : Animal(cat.type)
{
	type = cat.getType();
	brain = new Brain(*cat.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat  &Cat::operator = (const Cat &cat)
{
    std::cout << "Cat copy operator called" << std::endl;
    if (this != &cat)
    {
        Animal::operator=(cat);
        this->type = cat.type;
        brain = new Brain(*cat.brain);
    }
    return (*this);
}

Cat::~Cat()
{
	std::cout << "Default cat Destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "MAO" << std::endl;
}

std::string Cat::getIdeas(int i) const
{
	return (brain->getIdea(i));
}

void Cat::changeIdea(std::string newIdea, int i)
{
	brain->setIdea(newIdea, i);
}