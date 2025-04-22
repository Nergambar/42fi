#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &doggo);
		Dog &operator = (const Dog &doggo);

		virtual void makeSound() const;
};

#endif