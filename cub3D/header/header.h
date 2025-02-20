/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:39:55 by ctuiango          #+#    #+#             */
/*   Updated: 2025/02/02 14:39:58 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define WIDTH 1280
# define HEIGTH 720
# define BLOCK 64
# define DEBUG 1

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define SPEED 3

# define PI 3.14159265359

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_vars	t_vars;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	float	cos_angle;
	float	sin_angle;
	float	cos_ang;
	float	sin_ang;
	float	ray_x;
	float	ray_y;
	float	new_x;
	float	new_y;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	left_rotate;
	bool	right_rotate;

	t_vars	*vars;
}	t_player;

typedef struct s_vars
{
	void				*mlx;
	void				*win;
	void				*img;
	void				*textures[4];
	char				*tex_data[4];
	char				*data;
	char				**map;
	t_player			player;
	float				dist;
	float				height;
	float				x1;
	float				x2;
	int					x;
	int					y;
	int					bpp;
	int					size_line;
	int					endian;
	int					start_y;
	int					end;
	int					tex_y;
	int					pix_color;
	int					tex_bpp[4];
	int					tex_sl[4];
	int					tex_end[4];
	int					tex_width;
	int					tex_height;
	int					tex_x;
}	t_vars;

void	init_player(t_player *player, t_vars *vars);
void	move_player(t_player *player, t_vars *vars);
void	init_vars(t_vars *vars);
void	destroy_image(t_vars *vars);
void	draw_map(t_vars *vars);
void	set_images(t_vars *vars);
void	draw_square(int size, int color, t_vars *vars);
void	clear_image(t_vars *vars);
void	draw_square_aux(int size, int color, t_vars *vars);
void	draw_loop_one(t_vars *vars);
void	put_pixel(int x, int y, int color, t_vars *vars);
void	draw_background(t_vars *vars, int sky_color, int floor_color);
void	load_textures(t_vars *vars);
void	render_texture_column(t_vars *vars, int texture_index,
			int column, int start_y);
int		close_exit(void *noth);
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_player *player);
int		close_esc(t_vars *vars);
int		draw_loop(t_vars *vars);
bool	touch(float px, float py, t_vars *vars);
float	fixed_dist(float y1, float y2, t_vars *vars);

#endif
