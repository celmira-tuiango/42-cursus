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

int	close_exit(void *noth)
{
	t_vars	*vars;
	
	vars = (t_vars *)noth;
	//free_split(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}
