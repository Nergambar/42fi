#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Default destructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Default Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.ideas[i];
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Default Copy operator called" << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = brain.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	return(ideas[i]);
}

void Brain::setIdea(std::string thought, int i)
{
	ideas[i] = thought;
}