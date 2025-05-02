/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:45:59 by cramos            #+#    #+#             */
/*   Updated: 2025/02/04 08:46:02 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int	is_map_closed(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y] != NULL)
	{
		x = 0;
		while (vars->map[y][x] == ' ' || vars->map[y][x] == '\t')
			x++;
		if (vars->map[y][x] != '1')
			return (0);
		y++;
	}
	y = 0;
	while (vars->map[y] != NULL)
	{
		x = ft_strlen(vars->map[y]) - 1;
		while (vars->map[y][x] == ' ' || vars->map[y][x] == '\t')
			x--;
		if (vars->map[y][x] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	closed_map_aux(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map[y] != NULL)
	{
		x = 0;
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][x] == ' ' || vars->map[y][x] == '\t')
			{
				if ((y > 0 && x < ft_strlen(vars->map[y - 1])
						&& vars->map[y - 1][x] == '0') ||
				(vars->map[y + 1] != NULL && x < ft_strlen(vars->map[y + 1])
				&& vars->map[y + 1][x] == '0') ||
				(x > 0 && vars->map[y][x - 1] == '0') ||
				(vars->map[y][x + 1] == '0'))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_top(t_vars *vars)
{
	int	x;
	int	last;

	x = 0;
	last = 0;
	while (vars->map[0][x] != '\0')
	{
		if (vars->map[0][x] == '0' || vars->map[0][x] == 'E'
		|| vars->map[0][x] == 'W' || vars->map[0][x] == 'N'
		|| vars->map[0][x] == 'S')
			return (0);
		x++;
	}
	while (vars->map[last] != NULL)
		last++;
	x = 0;
	while (vars->map[last - 1][x] != '\0')
	{
		if (vars->map[0][x] == '0' || vars->map[0][x] == 'E'
		|| vars->map[0][x] == 'W' || vars->map[0][x] == 'N'
		|| vars->map[0][x] == 'S')
			return (0);
		x++;
	}
	return (1);
}
