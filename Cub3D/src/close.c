/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:33:42 by ctuiango          #+#    #+#             */
/*   Updated: 2025/02/06 12:33:44 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int	close_esc(t_vars *vars)
{
	close_exit(vars);
	return (0);
}

static void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_exit(void *noth)
{
	int		i;
	t_vars	*vars;

	i = 0;
	vars = (t_vars *)noth;
	free_all(vars);
	free_map(vars->map);
	while (i < 4)
	{
		if (vars->textures[i])
			mlx_destroy_image(vars->mlx, vars->textures[i]);
		i++;
	}
	if (i == 4)
	{
		if (vars->img)
			mlx_destroy_image(vars->mlx, vars->img);
	}
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}
