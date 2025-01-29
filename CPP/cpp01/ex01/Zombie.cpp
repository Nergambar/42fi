/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:09:52 by negambar          #+#    #+#             */
/*   Updated: 2025/01/20 12:12:47 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){std::cout << "THEY'RE COMING..." << std::endl;}

Zombie::~Zombie(){std::cout << "barely made it through, phew!" << std::endl;}

void Zombie::announce(void){std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl;}

