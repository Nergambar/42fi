#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain *brain;
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &doggo);
		Dog &operator = (const Dog &doggo);

		virtual void makeSound() const;
		std::string getIdeas(int i) const;
		void changeIdeas(std::string idea, int i);
};

#endif