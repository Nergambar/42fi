/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:51:22 by negambar          #+#    #+#             */
/*   Updated: 2025/01/15 15:51:37 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::get_first_name() const
{
	return(first_name);
}

std::string Contact::get_last_name() const
{
	return(last_name);
}

std::string Contact::get_nickname() const
{
	return(nickname);
}

std::string Contact::get_phonenumber() const
{
	return(phonenumber);
}

std::string Contact::get_secret() const
{
	return(secret);
}