/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:28:48 by negambar          #+#    #+#             */
/*   Updated: 2025/03/03 11:34:40 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

class	ClapTrap
{
	protected:
		std::string 			name;
		unsigned int			hitPoints;
		unsigned int			energyPoints;
		unsigned int			attackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string Name);
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator = (const ClapTrap &src);

		std::string getName(void) const;
		unsigned int getHP(void) const;
		unsigned int getEP(void) const;

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		~ClapTrap();
};

#endif