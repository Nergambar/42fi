/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:01:05 by negambar          #+#    #+#             */
/*   Updated: 2025/01/17 11:09:06 by negambar         ###   ########.fr       */
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
		std::string first_name;//(attributo)
		std::string last_name;
		std::string nickname;
		std::string phonenumber;
		std::string secret;

	public: //means other classes can access this part
		Contact(); //initialises the class (metodo, possono essere privati)
		~Contact(); //destroys said class
		int			addnew();
		void		show_contact() const; // const non modificano le var e possono lavorare sulle connst e non
		void		list(int i) const;
		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_nickname() const;
		std::string get_phonenumber() const;
		std::string get_secret() const;

		void set_first_name(std::string &s);
		void set_last_name(std::string &s);
		void set_nickname(std::string &s);
		void set_secret(std::string &s);
		void set_phonenumber(std::string &s);
};

#endif