#include "iter.hpp"

void printInt(int x)
{
	std::cout << x << " ";
}

void printChar(char c)
{
	std::cout << c << " ";
}

void printString(const std::string &c)
{
	std::cout << c << " ";
}

void printDouble(double x)
{
    std::cout << x << " ";
}

int main() {
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Integer array: ";
    iter(intArray, 5, printInt);
    std::cout << std::endl;

    // Test with an array of strings
    std::string strArray[] = {"Hello", "World", "42", "CPP"};
    std::cout << "String array: ";
    iter(strArray, 4, printString);
    std::cout << std::endl;

    // Test with an array of doubles
    std::cout << "Double array: ";
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    iter(doubleArray, 4, printDouble);
    std::cout << std::endl;

    return 0;
}