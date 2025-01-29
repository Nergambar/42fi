#ifndef HUMANB_HPP
#define HUMANB_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class Weapon;

class HumanB
{
	private:
		std::string name;
		Weapon *weapon; //puo' anche non esistere(?)
		bool	armed;
	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon &weapon);
		void	attack();
};

#endif