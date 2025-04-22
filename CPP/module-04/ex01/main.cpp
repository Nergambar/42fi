#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Dog p;
	std::cout << std::endl;
	
	Dog basic;
	basic.changeIdeas("bao",0);

	Dog tmp = basic;

	std::cout << basic.getIdeas(0) << std::endl;
	std::cout << tmp.getIdeas(0) << std::endl;

	p.changeIdeas("ciao", 0);
	Animal  *animale[20];
	for (int i = 0; i < 10; i++)
	{
		animale[i] = new Dog();
		((Dog *)animale[i])->changeIdeas("ciao", i);
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		animale[i] = new Cat();
		((Cat *)animale[i])->changeIdea("bao", i);
	}
	for (int i = 10; i < 20; i++) // Fix the loop to initialize the remaining 10 animals
	{
		animale[i] = new Dog();
		((Dog *)animale[i])->changeIdeas("										ciao", i);
	}
	for (int i = 0; i < 20; i++)
	{
		std::string idea;
		if (i < 10)
		{
			idea = ((Cat *)animale[i])->getIdeas(i);
			std::cout << idea << std::endl;
		}
		else
		{
			idea = ((Dog *)animale[i])->getIdeas(i);
			std::cout << idea << std::endl;
		}
	}
	delete j; // should not create a leak
	delete i;
	for (int i = 0; i < 20; i++)
	{
		delete animale[i];
	}
	std::cout << std::endl;
	return 0;
}
