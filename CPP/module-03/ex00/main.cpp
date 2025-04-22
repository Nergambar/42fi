/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:01:26 by negambar          #+#    #+#             */
/*   Updated: 2025/02/21 15:19:16 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	marco = ClapTrap("Marco");

	ClapTrap	sergio = marco;
	ClapTrap	s[3];

	marco.attack("a worm");
	std::cout << std::endl;
	marco.attack("a worm");
	std::cout << std::endl;
	marco.attack("a worm");
	std::cout << std::endl;
	marco.attack("a worm");
	std::cout << std::endl;
	marco.attack("a worm");
	std::cout << std::endl;
	marco.attack("a worm");
	std::cout << std::endl;
	marco.attack("a worm");
	std::cout << std::endl;
	marco.attack("a worm");
	std::cout << std::endl;

	marco.takeDamage(9);
	std::cout << std::endl;
	marco.attack("a worm");
	std::cout << std::endl;
	marco.takeDamage(1);
	std::cout << std::endl;
	marco.attack("a worm"); // No more life
	std::cout << std::endl;
	marco.attack("a worm"); // If have one more life, will not have enough energy
	std::cout << std::endl;

	marco.beRepaired(5);
	std::cout << std::endl;
	marco.attack("a worm");
	std::cout << std::endl;
	marco.takeDamage(15);
	std::cout << std::endl;
	marco.beRepaired(10); // No more life
	std::cout << std::endl;
}
