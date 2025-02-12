/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:30:36 by ctuiango          #+#    #+#             */
/*   Updated: 2025/02/03 09:30:38 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	clear_image(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, vars);
			x++;
		}
		y++;
	}
}

void	draw_square_aux(int size, int color, t_vars *vars)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(vars->x + i, vars->y, color, vars);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(vars->x, vars->y + i, color, vars);
		i++;
	}
}

void	draw_loop_one(t_vars *vars)
{
	t_player	*player;

	player = &vars->player;
	vars->x = player->x;
	vars->y = player->y;
	draw_square(10, 0x00FF00, vars);
	draw_map(vars);
}

void	draw_background(t_vars *vars, int sky_color, int floor_color)
{
	int	y;
	int	x;
	
	y = 0;
	while (y < HEIGTH / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, sky_color, vars);
			x++;
		}
		y++;
	}
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, floor_color, vars);
			x++;
		}
		y++;
	}
}
