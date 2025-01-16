/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:51:54 by negambar          #+#    #+#             */
/*   Updated: 2025/01/15 15:55:27 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_first_name(std::string &s)
{
	first_name = s;
}

void Contact::set_last_name(std::string &s)
{
	last_name = s;
}

void Contact::set_nickname(std::string &s)
{
	nickname = s;
}

void Contact::set_phonenumber(std::string &s)
{
	phonenumber = s;
}

void Contact::set_secret(std::string &s)
{
	secret = s;
}