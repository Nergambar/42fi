#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();

	delete dog;
	delete cat;
	std::cout << std::endl;

	const WrongAnimal*	wani = new WrongAnimal();
	const WrongAnimal*	wcat = new WrongCat();

	std::cout << wani->getType() << " " << std::endl;
	wani->makeSound();
	std::cout << wcat->getType() << " " << std::endl;
	wcat->makeSound();

	delete wani;
	delete wcat;

	std::cout << std::endl;
	return 0;
}