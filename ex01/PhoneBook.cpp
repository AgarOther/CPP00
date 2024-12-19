/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:50:40 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/18 23:57:29 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = -1;
	std::cout << "This is your personal Phone Book!" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Book successfully burned!" << std::endl;
}

void	PhoneBook::add(void)
{
	bool		was_new;
	std::string	tmp;
	Contact		contact;

	// Index check
	if (this->_index > 7)
	{
		this->_index = 0;
		std::cout << "[INFO] Contact list is full! Overwriting contact #1." << std::endl;
	}
	else if (this->_index == -1)
	{
		was_new = 1;
		this->_index++;
	}
	else
		was_new = 0;

	// Registering contact
	contact = this->_contacts[this->_index];
	tmp = "";
	std::cout << "Enter contact's first name: ";
	while (!std::cin.eof() && tmp == "")
	{
		if (std::getline(std::cin, tmp) && tmp != "")
			contact.set_first_name(tmp);
	}
	if (std::cin.eof())
		return ;
	
	std::cout << "Enter contact's last name: ";
	tmp = "";
	while (!std::cin.eof() && tmp == "")
	{
		if (std::getline(std::cin, tmp) && tmp != "")
			contact.set_last_name(tmp);
	}
	if (std::cin.eof())
		return ;
	
	std::cout << "Enter contact's nickname: ";
	tmp = "";
	while (!std::cin.eof() && tmp == "")
	{
		if (std::getline(std::cin, tmp) && tmp != "")
			contact.set_nick_name(tmp);
	}
	if (std::cin.eof())
		return ;
	
	std::cout << "Enter contact's phone number: ";
	tmp = "";
	while (!std::cin.eof() && tmp == "")
	{
		if (std::getline(std::cin, tmp) && tmp != "")
			contact.set_phone_number(tmp);
	}
	if (std::cin.eof())
		return ;
	
	std::cout << "Enter contact's darkest secret: ";
	tmp = "";
	while (!std::cin.eof() && tmp == "")
	{
		if (std::getline(std::cin, tmp) && tmp != "")
			contact.set_secret(tmp);
	}
	if (std::cin.eof())
		return ;
	
	// Empty fields check
	if (is_empty(contact.get_first_name()) || is_empty(contact.get_last_name()) || is_empty(contact.get_nick_name())
			|| is_empty(contact.get_phone_number()) || is_empty(contact.get_secret()))
	{
		std::cout << "You can't have empty infos in your contact! Aborting." << std::endl;
		// Setting index back to -1 so SEARCH returns no contacts if book previously had none
		if (was_new)
			this->_index = -1;
		return ;
	}

	// Adding contact to book and incrementing index
	this->_contacts[this->_index] = contact;
	this->_index++;
	std::cout << "Contact successfully created!" << std::endl;
}

void	PhoneBook::search(void)
{
	std::string tmp;
	int			id;
	Contact 	contact;

	if (this->_index == -1)
	{
		std::cout << std::endl << "Your PhoneBook has no contacts yet!" << std::endl;
		return ;
	}
	print_contacts(this->_contacts);
	std::cout << std::endl << "Please provide a contact ID: ";
	while (!std::cin.eof() && tmp == "")
		std::getline(std::cin, tmp);
	if (tmp.size() == 1 && tmp[0] >= '1' && tmp[0] <= '8')
	{
		id = tmp[0] - '0';
		if (id >= this->_index + 1)
		{
			std::cout << "No contact exists for this ID." << std::endl;
			return ;
		}
		contact = this->_contacts[id - 1];
		std::cout << "Index: " << id << std::endl;
		std::cout << "First name: " << contact.get_first_name() << std::endl;
		std::cout << "Last name: " << contact.get_last_name() << std::endl;
		std::cout << "Nickname: " << contact.get_nick_name() << std::endl;
		std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
		std::cout << "Darkest secret: " << contact.get_secret() << std::endl;
	}
	else
	{
		std::cout << std::endl << "Wrong input. Please only enter a digit between 1 and 8." << std::endl;
		if (std::cin.eof())
			return ;
		this->search();
	}
}