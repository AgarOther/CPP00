/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:53:03 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/20 13:43:13 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook book;
	std::string	input;

	while (input != "EXIT")
	{
		std::cout << "phonebook> ";
		std::getline(std::cin, input);
		if (input == "ADD")
			book.add();
		else if (input == "SEARCH")
			book.search();
		else if (input != "EXIT")
			std::cout << std::endl << "Invalid arguments. Valid entries are: ADD | SEARCH | EXIT" << std::endl;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
}