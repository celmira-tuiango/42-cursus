/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:19:04 by cramos            #+#    #+#             */
/*   Updated: 2025/02/12 16:19:08 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	extantion(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			if (str[i] == 'c' && str[i + 1] == 'u' && str[i + 2] == 'b')
				return ;
			else
			{
				printf("Error\n Invalid extantion\n");
				exit(0);
			}
		}
		i++;
	}
}

int	extantion_xpm(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 1;
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			if (str[i] == 'x' && str[i + 1] == 'p' && str[i + 2] == 'm')
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (0);
}
