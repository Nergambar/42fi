/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:05:40 by negambar          #+#    #+#             */
/*   Updated: 2025/01/15 16:40:53 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : index(0), n_contacts(0)
{}

PhoneBook::~PhoneBook()
{}

int PhoneBook::current() const
{
	return(index);
}

int PhoneBook::number() const
{
	return(n_contacts);
}

int PhoneBook::push_contact()
{
	if (index + 1 > 8)
		index = 0;
	if (_contact[index].addnew())
		return (1);
	index++;
	if(n_contacts < 8)
		n_contacts++;
	return (0);
}

void PhoneBook::dcontact(int i) const
{
	_contact[i].show_contact();
}

int PhoneBook::display(int n_contacts) const
{
	if (n_contacts == 0)
	{
		std::cout << std::right << "Empty phone book atm" << std::endl;
		return (1);
	}
	std::cout << "#index #First Name #Last Name #Nickname #" << std::endl;
	for (int i = 0; i < n_contacts; i++)
		_contact[i].list(i);
	std:: cout << "\n";
	std::cout << "#########################################" << std::endl;
	return (0);
}