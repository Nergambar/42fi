/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:35:26 by negambar          #+#    #+#             */
/*   Updated: 2025/02/28 11:45:23 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << RED << "FragTrap default constructor called" << RESET << std::endl;
	name = "default";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 0;
}

FragTrap::FragTrap(const FragTrap &FragTrap)
{
	name = FragTrap.getName();
	hitPoints = FragTrap.getHP();
	energyPoints = FragTrap.getEP();
	std::cout << RED <<"FragTrap copy constructor called" << RESET << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &fragTrap)
{
	std::cout << RED << "FragTrap copy operator called" << RESET << std::endl;
	if (this != &fragTrap)
	{
		name = fragTrap.getName();
		hitPoints = fragTrap.getHP();
		energyPoints = fragTrap.getEP();
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap default destructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << RED << "FragTrap constructor called" << RESET << std::endl;
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 0;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << BLUE << name << " gave their friend an high five" << RESET << std::endl;
}