#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		virtual ~WrongCat();
		WrongCat(const WrongCat &cat);
		WrongCat &operator = (const WrongCat &src);

		void	makeSound() const;
};

#endif