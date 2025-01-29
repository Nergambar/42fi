/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:37:06 by negambar          #+#    #+#             */
/*   Updated: 2025/01/22 12:44:40 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "HumanB.hpp"
#include "HumanA.hpp"
#include <string>
#include <iostream>

class Weapon{
	private:
		std::string	type;
	public:
		Weapon(std::string type);
		const std::string &getType() const;
		void setType(std::string type);
		~Weapon();
};

#endif