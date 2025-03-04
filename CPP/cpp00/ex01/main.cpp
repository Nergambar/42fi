/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:34:33 by negambar          #+#    #+#             */
/*   Updated: 2025/01/17 17:38:46 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string input;
	PhoneBook phonebook;
	int			j = 0;

	while (true)
	{
		std::cout << "Please enter your command! (ADD/SEARCH/EXIT)" << std::endl;
		if (!(std::getline(std::cin, input)))
			return (1);
		if (input == "ADD")
		{
			if (phonebook.push_contact())
				return (1);
		}
		else if (input == "SEARCH")
		{
			if (!phonebook.display(phonebook.number()))
			{
				std::cout << "Enter the index of the contact you want to search: " << std::endl;
				while (true)
				{
					if (!(std::getline(std::cin, input)))
						return(1);
					bool valid = true;
					for (int i = 0; i < input.length(); i++)
					{
						if (!std::isdigit(input[i]))
						{
							std::cout << "Wrong Index Value (range: 1 - " << phonebook.number() << ")" << std::endl;
							valid = false;
							break;
						}
					}
					if (valid)
					{
						int index = std::atoi(input.c_str());
						if (index <= phonebook.number() && index >= 1)
						{ 
							phonebook.dcontact(index - 1); 
							break;
						}
						else
							std::cout << "Wrong Index Value (range: 1 - " << phonebook.number() << ")" << std::endl;
					}
				}
			}
		}
		else if (input == "EXIT")
		{
			std::cout << "deleting all the contacts.\nyou're a monster, you know that right??" << std::endl;
			break;
		}
		else
			std::cout << "Invalid input. Try again." << std::endl;
	}
	return (0);
}
