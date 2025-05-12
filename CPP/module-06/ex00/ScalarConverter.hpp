#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <limits>
#include <cstring>
#include <iostream>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator = (const ScalarConverter &cpy);
		~ScalarConverter();
		static void convert(std::string literal);
};

#endif