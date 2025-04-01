/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:17:54 by ctuiango          #+#    #+#             */
/*   Updated: 2025/03/31 07:58:55 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	to_upper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		std::cout << (char)std::toupper(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
	else
	{
		int i = 1;
		while (i < ac)
		{
			to_upper(av[i]);
			i++;
		}
		std::cout << "\n";
	}
	return (0);
}
