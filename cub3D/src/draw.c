/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:18:08 by ctuiango          #+#    #+#             */
/*   Updated: 2025/02/03 09:18:10 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void	put_pixel(int x, int y, int color, t_vars *vars)
{
	int	index;

	if (x >= WIDTH || y >= HEIGTH || x < 0 || y < 0)
		return ;
	index = y * vars->size_line + x * vars->bpp / 8;
	vars->data[index] = color & 0xFF;
	vars->data[index + 1] = (color >> 8) & 0xFF;
	vars->data[index + 2] = (color >> 16) & 0xFF;
}

void	draw_square(int size, int color, t_vars *vars)
{
	int	i;

	i = 0;
	draw_square_aux(size, color, vars);
	while (i < size)
	{
		put_pixel(vars->x + size, vars->y + i, color, vars);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(vars->x + i, vars->y + size, color, vars);
		i++;
	}
}

void	draw_map(t_vars *vars)
{
	int		color;
	int		x;
	int		y;
	char	**map;

	y = 0;
	color = 0x0000FF;
	map = vars->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			vars->x = x * BLOCK;
			vars->y = y * BLOCK;
			if (map[y][x] == '1')
				draw_square(BLOCK, color, vars);
			x++;
		}
		y++;
	}
}

static void	draw_line(t_player *player, t_vars *vars, float start_x, int i)
{
	player->cos_angle = cos(start_x);
	player->sin_angle = sin(start_x);
	player->ray_x = player->x;
	player->ray_y = player->y;
	while (!touch(player->ray_x, player->ray_y, vars))
	{
		if (DEBUG)
			put_pixel(player->ray_x, player->ray_y, 0xFF0000, vars);
		player->ray_x += player->cos_angle;
		player->ray_y += player->sin_angle;
	}
	if (!DEBUG)
	{
		vars->x1 = player->x;
		vars->x2 = player->ray_x;
		vars->dist = fixed_dist(player->y, player->ray_y, vars);
		vars->height = (BLOCK / vars->dist) * (WIDTH / 2);
		vars->start_y = (HEIGTH - vars->height) / 2;
		vars->end = vars->start_y + vars->height;
		while (vars->start_y < vars->end)
		{
			put_pixel(i, vars->start_y, 255, vars);
			vars->start_y++;
		}
	}
}

int	draw_loop(t_vars *vars)
{
	float		fraction;
	float		start_x;
	t_player	*player;
	int			i;

	player = &vars->player;
	move_player(player);
	clear_image(vars);
	if (DEBUG)
		draw_loop_one(vars);
	fraction = PI / 3 / WIDTH;
	start_x = player->angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		draw_line(player, vars, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
