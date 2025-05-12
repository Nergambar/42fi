#include "Data.hpp"

Data::Data() : str("def"), num(1)
{
	std::cout << "Default Data constructor called" << std::endl;
}

Data::Data(const Data &src)
{
	*this = src;
	std::cout << "Data copy constructor called" << std::endl;
}

Data::Data(std::string str, int num)
{
	this->str = str;
	this->num = num;
}

Data::~Data()
{
	std::cout << "Default destructor called" << std::endl;
}

Data &Data::operator=(const Data &cpy)
{
	if (this != &cpy)
	{
		*this = cpy;
	}
	std::cout << "Data copy operator called" << std::endl;
	return(*this);
}

std::string Data::getStr()
{
	return str;
}

int Data::getNum()
{
	return num;
}
