/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:51:39 by negambar          #+#    #+#             */
/*   Updated: 2025/01/29 11:14:22 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::debug()
{
	std::cout << "something fishy is going on here, and you know I don't like fishes!" << std::endl;
}

void	Harl::info()
{
	std::cout << "Look at all this **fish** Gromit!" << std::endl;
	std::cout << "you don't have to bring me more fishes!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "Where are the fishes, Gromit?? Where are the fishes??" << std::endl;
}

void	Harl::error()
{
	std::cout << "Where'd all the **fish** go, starting to flyyyyy" << std::endl;
}

void	Harl::complain(std::string level)
{
	void	((Harl::*list[4])(void)) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*list[i])();
			break ;
		}
	}
}