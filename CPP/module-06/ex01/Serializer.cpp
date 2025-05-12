#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	(void)src;
	std::cout << "Default copy constructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &cpy)
{
	(void)cpy;
	std::cout << "Default copy operator called" << std::endl;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Default destructor called" << std::endl; 
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}