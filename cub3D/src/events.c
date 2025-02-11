/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:39:43 by ctuiango          #+#    #+#             */
/*   Updated: 2025/02/02 14:39:46 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

int	key_press(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = true;
	if (keycode == S)
		player->key_down = true;
	if (keycode == A)
		player->key_left = true;
	if (keycode == D)
		player->key_right = true;
	if (keycode == LEFT)
		player->left_rotate = true;
	if (keycode == RIGHT)
		player->right_rotate = true;
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}

static void	angle(t_player *player)
{
	float		angle_speed;
	float		cos_angle;
	float		sin_angle;
	int			speed;

	angle_speed = 0.03;
	speed = 3;
	player->new_x = player->x;
	player->new_y = player->y;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	if (player->key_up)
	{
		player->new_x += cos_angle * speed;
		player->new_y += sin_angle * speed;
	}
}

void	move_player(t_player *player, t_vars *vars)
{
	float		cos_angle;
	float		sin_angle;
	int			speed;

	speed = 3;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	player->new_x = player->x;
	player->new_y = player->y;
	angle(player);
	if (player->key_down)
	{
		player->new_x -= cos_angle * speed;
		player->new_y -= sin_angle * speed;
	}
	if (player->key_left)
	{
		player->new_x += sin_angle * speed;
		player->new_y -= cos_angle * speed;
	}
	if (player->key_right)
	{
		player->new_x -= sin_angle * speed;
		player->new_y += cos_angle * speed;
	}
	if (!touch(player->new_x, player->y, vars))
		player->x = player->new_x;
	if (!touch(player->x, player->new_y, vars))
		player->y = player->new_y;
}
