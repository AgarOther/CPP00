/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:53:39 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/19 00:28:06 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	str_right_align(std::string str)
{
	int	size;
	std::string	spaces;

	size = str.size();
	if (size >= 10)
		return (str);
	for (int i = 0; i < 10 - size + 1; i++)
		spaces.append(" ");
	str = spaces + str;
	return (str);
}

std::string str_truncate(std::string str)
{
	if (str.size() > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	str = str_right_align(str);
	return (str);
}

void	print_contacts(Contact contacts[8])
{
	std::cout << "******************************* MY AWESOME PHONEBOOK *******************************" << std::endl;
	std::cout << "*   Index   | First Name | Last  Name |  Nickname  | Phone Number | Darkest Secret *" << std::endl;
	std::cout << "*-----------|------------|------------|------------|--------------|----------------*" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].get_first_name() != "")
		{
			std::cout << "*          " << i + 1 << "| " << str_truncate(contacts[i].get_first_name()) << "| " << 
				str_truncate(contacts[i].get_last_name()) << "| " << str_truncate(contacts[i].get_nick_name()) << "|    " <<
				str_truncate(contacts[i].get_phone_number()) << "|" << str_truncate(contacts[i].get_secret()) << "     *" << std::endl;
		}
	}
	std::cout << "************************************************************************************" << std::endl;
}