/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:53:44 by negambar          #+#    #+#             */
/*   Updated: 2025/01/15 16:41:09 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {
	public:
	PhoneBook();
	~PhoneBook();
	int	push_contact();
	int display(int n_contact) const;
	void dcontact(int index) const;
	int current() const;
	int number() const;

	private:
	int index;
	int n_contacts;
	Contact _contact[8];
};

#endif