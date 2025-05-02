/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:18:13 by ctuiango          #+#    #+#             */
/*   Updated: 2024/08/13 16:23:37 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	send(int pid, char *st)
{
	int	bit;
	int	i;

	while (*st)
	{
		bit = 8;
		while (bit--)
		{
			i = ((*st >> bit) & 1);
			if (i == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(600);
		}
		++st;
	}
}

int	main(int ac, char **av)
{
	int		id;
	char	*str;

	str = ft_strdup(av[2]);
	if (ac == 3)
	{
		id = ft_atoi(av[1]);
		send(id, str);
	}
	else
		ft_printf("Argument Passing Error!\n");
	free(str);
	return (0);
}
