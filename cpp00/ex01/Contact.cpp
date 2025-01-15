/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:53:42 by negambar          #+#    #+#             */
/*   Updated: 2025/01/14 14:56:49 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

int	Contact::addnew(Contact *c)
{
	std::string input;

	std::cout << "Enter First Name: "; //cout = c output (write+-)
	while (input.length() < 1) //loops until input isn't NULL
	{
		input.erase();
		if(!(std::getline(std::cin, input)))
			return(1);
	}
	c->first_name = input;
	input.erase();
	std::cout << "Enter Last Name : ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return(1);
	}
	c->last_name = input;
	input.erase();
	std::cout << "Enter Nickname : ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return(1);
	}
	c->nickname = input;
	input.erase();
	std::cout << "Enter Phone Number : ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	c->phonenumber = input;
	input.erase();
	std::cout << "Enter Darkest Secret : ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	c->secret = input;
	return (0);
}

void Contact::show_contact() const
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phonenumber << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void Contact::list(int i) const
{
	std::cout << std::left << std::setw(10) << (i + 1) << "|"; //setw = set width, left = justify to the left
	if (first_name.size() > 10)
		std::cout << std::left << std::setw(9) << first_name.substr(0, 9) << "." << "|";
	else
		std::cout << std::left << std::setw(10) << first_name.substr(0, 10) << "." << "|";
	if (last_name.size() > 10)
		std::cout << std::left << std::setw(9) << last_name.substr(0, 9) << "." << "|";
	else
		std::cout << std::left << std::setw(10) << last_name.substr(0, 10) << "." << "|";
	if (nickname.size() > 10)
		std::cout << std::left << std::setw(9) << nickname.substr(0, 9) << "." << "|";
	else
		std::cout << std::left << std::setw(9) << nickname.substr(0, 9) << "." << "|";
	std::cout << "\n";
}
