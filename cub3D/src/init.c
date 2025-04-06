/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:03:16 by ctuiango          #+#    #+#             */
/*   Updated: 2025/02/03 09:03:26 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static void	init_look(char c, t_player *player)
{
	if (c == 'N')
		player->angle = 3 * PI / 2;
	else if (c == 'S')
		player->angle = PI / 2;
	else if (c == 'E')
		player->angle = 0;
	else if (c == 'W')
		player->angle = PI;
}

static void	init_player_pos(t_player *player, t_vars *vars)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			c = vars->map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				player->x = x * vars->block + vars->block / 2;
				player->y = y * vars->block + vars->block / 2;
				init_look(c, player);
				vars->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_player(t_player *player, t_vars *vars)
{
	init_player_pos(player, vars);
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGTH, "Cub3D");
	vars->textures[0] = NULL;
	vars->textures[1] = NULL;
	vars->textures[2] = NULL;
	vars->textures[3] = NULL;
	vars->img = NULL;
	load_textures(vars);
	init_player(&vars->player, vars);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGTH);
	vars->data = mlx_get_data_addr(vars->img, &vars->bpp,
			&vars->size_line, &vars->endian);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
