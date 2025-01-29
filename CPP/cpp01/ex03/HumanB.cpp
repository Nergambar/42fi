#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	std::cout << "\t\t\t\t" << this->name << " joined the battlefield!" << std::endl;
	this->armed = false;
}

HumanB::~HumanB()
{
	std::cout << "\t\t\t\t" << this->name << " left the battle!" << std::endl;
}

void HumanB::attack()
{
	if (!(this->armed))
		std::cout << name << " has no weapon" << std::endl;
	else
		std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	this->armed = true;
	std::cout << this->name << " has a " << this->weapon->getType() << std::endl; 
}