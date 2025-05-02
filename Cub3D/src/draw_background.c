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

void	draw_background(t_vars *vars, int sky_color, int floor_color)
{
	int	y;
	int	x;

	y = 0;
	sky_color = vars->ceiling_hex;
	floor_color = vars->floor_hex;
	while (y < HEIGTH / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x++, y, sky_color, vars);
		}
		y++;
	}
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x++, y, floor_color, vars);
		}
		y++;
	}
}
