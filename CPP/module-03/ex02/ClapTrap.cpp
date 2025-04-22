/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:35:26 by negambar          #+#    #+#             */
/*   Updated: 2025/02/21 15:42:24 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Marco"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << MAGENTA << "claptrap default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) : attackDamage(0)
{
	name = clapTrap.getName();
	hitPoints = clapTrap.getHP();
	energyPoints = clapTrap.getEP();
	std::cout << MAGENTA << "claptrap copy constructor called" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &clapTrap)
{
	std::cout << MAGENTA << "claptrap copy operator called" << RESET << std::endl;
	if (this != &clapTrap)
	{
		name = clapTrap.getName();
		hitPoints = clapTrap.getHP();
		energyPoints = clapTrap.getEP();
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << MAGENTA << "claptrap default destructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << MAGENTA << "claptrap constructor called" << RESET << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (name);
}

unsigned int ClapTrap::getHP() const
{
	return(hitPoints);
}

unsigned int ClapTrap::getEP() const
{
	return(energyPoints);
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
		return;
	if (energyPoints)
	{
		std::cout << RED << name << " attacks " << target << " causing " << attackDamage << " damage" << RESET << std::endl;
		energyPoints--;
	}
	else
		std::cout << name << "'s attack failed, out of energy" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
		return;
	hitPoints -= amount;
	std::cout << BLUE << name << " took " << amount << " damage, they now have " << hitPoints << " left" << RESET << std::endl;
	if (hitPoints <= 0)
		std::cout << name << " died of death" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << GREEN << name << "can't be repaired, they're dead" << RESET << std::endl;
		return;
	}
	if (energyPoints)
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << GREEN << "Repairing " << name << " for " << amount << " hp, they now have " << hitPoints << " hp" << RESET << std::endl;
	}
	else
		std::cout << name << "'s repairing failed, out of energy" << std::endl;
}
