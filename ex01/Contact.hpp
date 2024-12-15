/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:35:53 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/15 01:44:16 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string _first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_phone_number;
		std::string	_secret;
	public:
		Contact(void);
		~Contact(void);
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nick_name(void) const;
		std::string	get_phone_number(void) const;
		std::string	get_secret(void) const;
		void		set_first_name(std::string first_name);
		void		set_last_name(std::string last_name);
		void		set_nick_name(std::string nick_name);
		void		set_phone_number(std::string phone_number);
		void		set_secret(std::string secret);
};

#endif