#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>
#include <string>


class Animal{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &animal);
		virtual ~Animal();

		virtual void makeSound() const = 0;
		virtual std::string getType() const;
		Animal &operator = (const Animal &animal);
};

#endif