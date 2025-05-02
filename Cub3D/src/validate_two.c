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
	int	len;

	len = ft_strlen(str);
	if (!((str[len - 1] == 'b') && (str[len - 2] == 'u')
			&& (str[len - 3] == 'c') && (str[len - 4] == '.')))
	{
		printf("Error\n Invalid extantion\n");
		exit(0);
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
