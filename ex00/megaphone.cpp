/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:15:34 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 20:15:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static std::string	argv_to_string(int argc, char **argv)
{
	std::string	str;

	for (int i = 1; i < argc; i++)
		str += argv[i];
	return (str);
}

static std::string	ft_capitalize(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (std::isalpha(str[i]))
			str[i] = std::toupper(str[i]);
	}
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::cout << ft_capitalize(argv_to_string(argc, argv)) << std::endl;
}
