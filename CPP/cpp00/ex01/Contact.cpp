/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:53:42 by negambar          #+#    #+#             */
/*   Updated: 2025/01/17 17:26:36 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

int	Contact::addnew()
{
	std::string input;

	std::cout << "Enter First Name: "; //cout = c output (write+-)
	while (input.length() < 1) //loops until input isn't NULL
	{
		input.erase();
		if(!(std::getline(std::cin, input)))
			return(1);
	}
	set_first_name(input);
	input.erase();
	std::cout << "Enter Last Name : ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return(1);
	}
	set_last_name(input);
	input.erase();
	std::cout << "Enter Nickname : ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return(1);
	}
	set_nickname(input);
	input.erase();
	std::cout << "Enter Phone Number : ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	set_phonenumber(input);
	input.erase();
	std::cout << "Enter Darkest Secret : ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	set_secret(input);
	return (0);
}

void Contact::show_contact() const
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "First Name: " << get_first_name() << std::endl;
	std::cout << "Last Name: " << get_last_name() << std::endl;
	std::cout << "Nickname: " << get_nickname() << std::endl;
	std::cout << "Phone number: " << get_phonenumber() << std::endl;
	std::cout << "Darkest secret: " << get_secret() << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void Contact::list(int i) const
{
    std::cout << std::right << std::setw(10) << (i + 1) << "|"; //setw = set width, left = justify to the left
    if (first_name.size() > 10)
        std::cout << std::right << std::setw(9) << first_name.substr(0, 9) << "." << "|";
    else
        std::cout << std::right << std::setw(10) << first_name.substr(0, 10) << "|";
    if (last_name.size() > 10)
        std::cout << std::right << std::setw(9) << last_name.substr(0, 9) << "." << "|";
    else
        std::cout << std::right << std::setw(10) << last_name.substr(0, 10) << "|";
    if (nickname.size() > 10)
        std::cout << std::right << std::setw(9) << nickname.substr(0, 9) << "." << "|";
    else
        std::cout << std::right << std::setw(10) << nickname.substr(0, 10) << "|";
    std::cout << "\n";
}
