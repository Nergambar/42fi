/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:38:34 by negambar          #+#    #+#             */
/*   Updated: 2025/03/03 11:32:08 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(10)
{
	std::cout << "claptrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name)
{
	std::cout << "Parametric constructor called for " << this->name << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 10;
}

ClapTrap::ClapTrap(const ClapTrap &clap)
{
	std::cout << "Copy constructor called for " << clap.getName() << std::endl;
	*this = clap;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for " << this->name << std::endl;
}

ClapTrap	&ClapTrap::operator = (const ClapTrap &src)
{
	if (this != &src)
	{
		std::cout << "Copy assignment called for " << src.getName() << std::endl;
		this->name = src.getName();
		this->hitPoints = src.getHP();
		this->energyPoints = src.getEP();
		this->attackDamage = src.getAD();
	}
	return *this;
}

std::string ClapTrap::getName(void) const
{
	return this->name;
}

unsigned int ClapTrap::getHP(void) const
{
	return this->hitPoints;
}

unsigned int ClapTrap::getEP(void) const
{
	return this->energyPoints;
}

unsigned int ClapTrap::getAD(void) const
{
	return this->attackDamage;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " doesn't have any hit points or energy points left." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " doesn't have any hit points left." << std::endl;
		return;
	}
	if (this->hitPoints > amount)
		this->hitPoints -= amount;
	else
		this->hitPoints = 0;
	std::cout << "ClapTrap " << this->name << " took " << amount << " damage, now they have " << this->hitPoints << " hit points left..." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " doesn't have any hp or energy points left." << std::endl;
	}
	std::cout << "ClapTrap " << this->name << " won " << amount << " hit points, now they have " << this->hitPoints + amount << "!" << std::endl;
	this->hitPoints += amount;
	this->energyPoints--;
}