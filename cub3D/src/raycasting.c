/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:08:59 by ctuiango          #+#    #+#             */
/*   Updated: 2025/02/03 09:09:01 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_dist(float y1, float y2, t_vars *vars)
{
	float	delta_x;
	float	dela_y;
	float	angle;
	float	fix_dist;

	delta_x = vars->x2 - vars->x1;
	dela_y = y2 - y1;
	angle = atan2(dela_y, delta_x) - vars->player.angle;
	fix_dist = distance(delta_x, dela_y) * cos(angle);
	return (fix_dist);
}

bool	touch(float px, float py, t_vars *vars)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (vars->map[y][x] == '1')
		return (true);
	return (false);
} 
