/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:02:52 by negambar          #+#    #+#             */
/*   Updated: 2025/01/20 14:18:34 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string marco = "HI THIS IS BRAIN";
	std::string	*sergio = &marco;
	std::string &norman = marco;

	std::cout << "the original string was " << marco << std::endl;
	std::cout << "\nits pointer is " << sergio << std::endl;
	std::cout << "\nand it's address... " << norman << std::endl;
}