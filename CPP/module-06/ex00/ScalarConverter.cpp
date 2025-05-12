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
	if (literal.length() == 1 && !isdigit(c)) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
	else {
        if (isdigit(c))
            c = (char)i;
        f = round(d * 10.0f) / 10.0f;
    }

	if ((d > INT_MAX || d < INT_MIN) && !(literal == "nan" || literal == "inf" || literal == "-inf"
		|| literal == "nanf" || literal == "inff" || literal == "-inff"))
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: Surpasses limits" << std::endl;
	}
	else
	{
	// characters
		if (c < 32 || c >= 127
			|| literal == "nan" || literal == "inf" || literal == "-inf"
			|| literal == "nanf" || literal == "inff" || literal == "-inff")
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << c << std::endl;

		// intigers
		if (literal == "nan" || literal == "inf" || literal == "-inf"
			|| literal == "nanf" || literal == "inff" || literal == "-inff")
			std::cout << "int: " << "Non Displayable" << std::endl;
		else if (isprint(static_cast<int>(c)))
		{
			std::cout << "int: " << static_cast<int>(c) << std::endl;
		}
		
		else
			std::cout << "int: " << i << std::endl;
	}

	// floats
	if ((d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
		&& !(literal == "nan" || literal == "inf" || literal == "-inf"
		|| literal == "nanf" || literal == "inff" || literal == "-inff") && !isprint(static_cast<int>(c)))
	{
		std::cout << "float: Surpasses limits" << std::endl;	
		std::cout << "double: Surpasses limits" << std::endl;
	}
	else
	{
		if (literal == "nan" || literal == "inf" || literal == "-inf"
			|| literal == "nanf" || literal == "inff" || literal == "-inff")
			{
				if (strlen(literal.c_str()) == 3)
					std::cout << "float: " << literal << "f" << std::endl;
				else
					std::cout << "float: " << literal << std::endl;
			}
		else if (f == static_cast<int>(f)) // Check if float is a whole number
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
		else if (d == static_cast<int>(d))
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "wrong number of args" << std::endl;
	else
	{
		ScalarConverter *barto = new ScalarConverter;
		ScalarConverter::convert(av[1]);
		delete barto;
	}
}