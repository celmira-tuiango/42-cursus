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
#include <string.h>


static void init_player_pos(t_player *player, t_vars *vars)
{
	int y;
	int x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
		    if (vars->map[y][x] == 'N')
		    {
			player->x = x * 64 + 64 / 2;
			player->y = y * 64 + 64 / 2;
			player->angle = PI / 2;
			vars->map[y][x] = '0';
			return ;
		    }
		    x++;
		}
		y++;
	}
	player->x = WIDTH / 2;
	player->y = HEIGTH / 2;
	player->angle = PI / 2;
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

char	**get_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 11);
	map[0] = strdup("111111111111111");
    map[1] = strdup("100000010000001");
    map[2] = strdup("100010000001001");
    map[3] = strdup("100000100000001");
    map[4] = strdup("100010000010001");
    map[5] = strdup("100000010000001");
    map[6] = strdup("100001000100001");
    map[7] = strdup("100010000000001");
    map[8] = strdup("10N000000100001");
    map[9] = strdup("111111111111111");
	map[10] = NULL;
	return (map);
}

void	init_vars(t_vars *vars)
{
	vars->map = get_map();
	init_player(&vars->player, vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGTH, "Cub3D");
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGTH);
	vars->data = mlx_get_data_addr(vars->img, &vars->bpp,
			&vars->size_line, &vars->endian);
	load_textures(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
