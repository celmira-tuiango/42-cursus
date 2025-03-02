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
	free_map(vars->map);
	//free(vars->map);
	mlx_destroy_image(vars->mlx, vars->img);
	while (i < 4)
		mlx_destroy_image(vars->mlx, vars->textures[i++]);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}
