/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:15:01 by negambar          #+#    #+#             */
/*   Updated: 2025/02/18 14:33:08 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	guard_mode;

	public:
		ScavTrap();
		ScavTrap(std::string Name);
		ScavTrap(const ScavTrap &src);
		ScavTrap &operator = (const ScavTrap &src);

		~ScavTrap();

		bool	get_guardmode() const;
		void	guardGate();
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
};

#endif