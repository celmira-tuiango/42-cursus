/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:48:31 by cramos            #+#    #+#             */
/*   Updated: 2025/02/14 14:48:35 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int	last_arg(t_vars *vars)
{
	char	c;
	int		x;
	int		last;

	last = 0;
	while (vars->file_lines[last] != NULL)
		last++;
	if (last == 0)
		return (0);
	x = 0;
	while (vars->file_lines[last - 1][x] != '\0')
	{
		c = vars->file_lines[last - 1][x];
		if (c != '1' && c != ' ')
			return (0);
		x++;
	}
	return (1);
}

int	verif_colors(t_vars *vars)
{
	int	i;
	int	c;
	int	m;

	if (vars->count_f > 1 || (vars->count_c > 1))
		return (0);
	i = 0;
	while (i < 3)
	{
		c = vars->ceiling_color[i];
		m = vars->floor_color[i];
		if (c > 255 || c < 0)
			return (0);
		if (m > 255 || m < 0)
			return (0);
		i++;
	}
	return (1);
}
