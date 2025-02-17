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

void	init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGTH / 2;
	player->angle = PI / 2;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

char	**get_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 11);
	map[0] = "111111111111111";
	map[1] = "100000010000001";
	map[2] = "100010000001001";
	map[3] = "100000100000001";
	map[4] = "100010000010001";
	map[5] = "100000010000001";
	map[6] = "100001000100001";
	map[7] = "100010000000001";
	map[8] = "100000000100001";
	map[9] = "111111111111111";
	map[10] = NULL;
	return (map);
}

void	init_vars(t_vars *vars)
{
	init_player(&vars->player);
	vars->map = get_map();
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGTH, "Cub3D");
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGTH);
	vars->data = mlx_get_data_addr(vars->img, &vars->bpp,
			&vars->size_line, &vars->endian);
	load_textures(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
