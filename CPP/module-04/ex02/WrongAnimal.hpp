#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &wong);

		virtual ~WrongAnimal();
		WrongAnimal &operator = (const WrongAnimal &w);

		std::string	getType() const;
		void		makeSound() const;
};

#endif