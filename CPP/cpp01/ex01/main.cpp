/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:13:08 by negambar          #+#    #+#             */
/*   Updated: 2025/01/20 12:33:20 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "too few args!", 1);
	Zombie marco;

	int i = 0;
	for (i = 0; av[1][i] != '\0'; i++)
	{
		if (!isdigit(av[1][i]))
			return (std::cout << "not a valid input", 1);
	}
	Zombie *sergio = marco.zombieHorde(atoi(av[1]), "sergio");
	for (i = 0; i < atoi(av[1]); i++)
		sergio[i].announce();
	delete[] sergio;
	return 0;
}