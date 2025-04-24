#include "ScalarConverter.hpp"
#include <algorithm>

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Default destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
	(void)cpy;
	std::cout << "ScalarConverter copy operator called" << std::endl;
	return(*this);
}

void ScalarConverter::convert(std::string literal)
{
	char c = literal[0];
	int i = 0;
	float f = 0.0f;
	double d = 0.0;

	d = std::atof(literal.c_str());
	i = (int)d;
	if (isdigit(c))
		c = (char)i;
	f = round(d * 10.0f) / 10.0f;

	if ((d > INT_MAX || d < INT_MIN) && !(literal == "nan" || literal == "inf" || literal == "-inf"
		|| literal == "nanf" || literal == "inff" || literal == "-inff"))
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: Surpasses limits" << std::endl;
	}
	else
	{
	// characters
		if (i < 32 || i >= 127
			|| literal == "nan" || literal == "inf" || literal == "-inf"
			|| literal == "nanf" || literal == "inff" || literal == "-inff")
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << c << std::endl;

		// intigers
		if (literal == "nan" || literal == "inf" || literal == "-inf"
			|| literal == "nanf" || literal == "inff" || literal == "-inff")
			std::cout << "int: " << "Non Displayable" << std::endl;
		else
				std::cout << "int: " << i << std::endl;
	}

	if ((d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
		&& !(literal == "nan" || literal == "inf" || literal == "-inf"
		|| literal == "nanf" || literal == "inff" || literal == "-inff"))
	{
		std::cout << "float: Surpasses limits" << std::endl;	
		std::cout << "double: Surpasses limits" << std::endl;
	}
	else
	{
		// floats
		if (literal == "nan" || literal == "inf" || literal == "-inf"
			|| literal == "nanf" || literal == "inff" || literal == "-inff")
			{
				if (strlen(literal.c_str()) == 3)
					std::cout << "float: " << literal << "f" << std::endl;
				else
					std::cout << "float: " << literal << std::endl;
			}
		else if (f == std::atoi(literal.c_str()))
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;

		// doubles
		if (literal == "nan" || literal == "inf" || literal == "-inf"
			|| literal == "nanf" || literal == "inff" || literal == "-inff")
			{
				if (strlen(literal.c_str()) == 3 || (strlen(literal.c_str()) == 4 && literal[0] == '-'))
					std::cout << "double: " << literal << "f" << std::endl;
				else
					std::cout << "double: " << literal << std::endl;
			}
		else if (d == std::atoi(literal.c_str()))
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
}

int main(int ac, char **av)
{
	(void)ac;
	ScalarConverter *barto = new ScalarConverter;
	ScalarConverter::convert(av[1]);
	delete barto;
}