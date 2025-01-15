/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:01:05 by negambar          #+#    #+#             */
/*   Updated: 2025/01/13 13:04:00 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
# include <iostream>
# include <iomanip>
# include <string>

/*
	std::string ->	std = namespace
					"::" = accesses namespace
					string = built-in class for working with strings
*/
class Contact
{
	private: // means other classes cannot access this stuff
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phonenumber;
		std::string secret;

	public: //means other classes can access this part
		Contact(); //initialises the class
		~Contact(); //destroys said class
		int		addnew(Contact *contact);
		void	show_contact() const;
		void	list(int i) const;
};

#endif