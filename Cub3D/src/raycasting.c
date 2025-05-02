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
	vars->data[index + 2] = (color >> 16) & 0xFF;
	vars->data[index + 1] = (color >> 8) & 0xFF;
	vars->data[index] = color & 0xFF;
}

static void	aux_draw_line_one(t_vars *vars, t_player *player, float start_x)
{
	player->cos_angle = cos(start_x);
	player->sin_angle = sin(start_x);
	player->ray_x = player->x;
	player->ray_y = player->y;
	while (!touch(player->ray_x, player->ray_y, vars))
	{
		player->ray_x += player->cos_angle;
		player->ray_y += player->sin_angle;
	}
}

static void	aux_draw_line_two(t_vars *vars, t_player *player)
{
	vars->x1 = player->x;
	vars->x2 = player->ray_x;
	vars->dist = fixed_dist(player->y, player->ray_y, vars);
	vars->heightt = (vars->block / vars->dist) * (WIDTH / 2);
	vars->start_y = (HEIGTH - vars->heightt) / 2;
	vars->end = vars->start_y + vars->heightt;
	if (touch(player->ray_x - player->cos_angle, player->ray_y, vars))
		vars->tex_x = (int)player->ray_x % vars->tex_width;
	else
		vars->tex_x = (int)player->ray_y % vars->tex_width;
}

static void	draw_line(t_player *player, t_vars *vars, float start_x, int i)
{
	int	texture_index;

	aux_draw_line_one(vars, player, start_x);
	if (!DEBUG)
	{
		if (touch(player->ray_x - player->cos_angle, player->ray_y, vars))
		{
			if (player->ray_y > player->y)
				texture_index = 0;
			else
				texture_index = 1;
		}	
		else
		{
			if (player->ray_x < player->x)
				texture_index = 2;
			else
				texture_index = 3;
		}
		aux_draw_line_two(vars, player);
		render_texture_column(vars, texture_index, i,
			vars->start_y);
	}
}

int	draw_loop(t_vars *vars)
{
	float		fraction;
	float		start_x;
	t_player	*player;
	int			i;

	player = &vars->player;
	move_player(player, vars);
	draw_background(vars, 0x87CEEB, 0x8B4513);
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
