/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:01:04 by negambar          #+#    #+#             */
/*   Updated: 2025/01/20 12:23:42 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Zombie{
	public:
		Zombie();
		Zombie *zombieHorde(int N, std::string name);
		void	announce(void);
		~Zombie();

	private:
		std::string name;
};

#endif