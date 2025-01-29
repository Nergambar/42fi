/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:45:20 by negambar          #+#    #+#             */
/*   Updated: 2025/01/20 11:47:51 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie marco;
	Zombie *sergio;

	sergio = marco.newZombie("Sergio");
	marco.randomChump("Marco1");
	marco.randomChump("Marco2");
	marco.randomChump("Marco3");
	marco.randomChump("Marco4");
	sergio->announce();
	delete(sergio);
	return 0;
}