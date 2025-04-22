/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:24:02 by negambar          #+#    #+#             */
/*   Updated: 2025/03/03 11:51:25 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "scavtrap default constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	guard_mode = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Parametric ScavTrap constructor called for " << name << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	guard_mode = false;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "Copy ScavTrap constructor called for " << src.getName() << std::endl;
	*this = src;
}

ScavTrap	&ScavTrap::operator = (const ScavTrap &src)
{
	if (this != &src)
	{
		std::cout << "Copy assignment ScavTrap operator called for " << src.getName() << std::endl;
		name = src.getName();
		hitPoints = src.getHP();
		energyPoints = src.getEP();	
		guard_mode = src.get_guardmode();
	}
	return *this;
}

bool	ScavTrap::get_guardmode(void) const
{
	return guard_mode;
}

void	ScavTrap::guardGate(void)
{
	if(guard_mode)
		std::cout << "ScavTrap " << name << " was already in guard mode." << std::endl;
	else
	{
		this->guard_mode = true;
		std::cout << "ScavTrap " << name << " is now in guard mode." << std::endl;
	}
}

void	ScavTrap::attack(const std::string &target)
{
	if (hitPoints <= 0)
		return ;
	if (guard_mode == true)
	{
		std::cout << name << " can't attack, they are in guard mode" << std::endl;
		return; 
	}
	if (energyPoints)
	{
		std::cout << name << " attacks " << target << " with a " << attackDamage << " damage attack" << std::endl;
		energyPoints--;
	}
	else
		std::cout << name << "'s attack failed, out of energyPoints" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << name << " is already dead" << std::endl;
		return;
	}
	if (guard_mode == true)
	{
		std::cout << name << " took 0 damage, their guard is active" << std::endl;
		return ;
	}
	hitPoints -= amount;
	std::cout << name << " took " << amount << " damage, they now have " << hitPoints << " hp" << std::endl;
	if (hitPoints <= 0)
		std::cout << name << " died" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap Default destructor called" << std::endl;
}