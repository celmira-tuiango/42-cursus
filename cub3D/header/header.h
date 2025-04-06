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

# define BUFFER_SIZE 2024
# define TAB_SIZE 8

# define WIDTH 1280
# define HEIGTH 720
# define BLOCK 64
# define DEBUG 0

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define MIN_DIST 10

# define PI 3.14159265359

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <stdarg.h>
# include <ctype.h>
# include <string.h>
# include "../src/aux_func/header_aux.h"

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

typedef struct s_init
{
	char	**new_map;
	int		y;
	int		len;
	int		new_len;
	int		tab_count;
	int		i;
	int		x;
	int		j;
	int		t_y;
	int		t_x;
}	t_init;

typedef struct s_vars
{
	void				*mlx;
	void				*win;
	void				*img;
	void				*textures[4];
	char				*tex_data[4];
	char				*data;
	char				**map;
	char				*north_texture;
	char				*south_texture;
	char				*west_texture;
	char				*east_texture;
	char				**file_lines;
	t_init				init;
	t_player			player;
	float				dist;
	float				heightt;
	float				x1;
	float				x2;
	int					floor_hex;
	int					ceiling_hex;
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
	int					block;
	int					speed;
	int					floor_color[3];
	int					ceiling_color[3];
	int					map_count;
	int					height;
	int					width;
	int					count_f;
	int					count_c;
}	t_vars;

typedef struct s_bytes
{
	int	total_bytess;
}	t_bytes;

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
void	verify_color_line(char *line, t_vars *vars);
void	verify_textures(char **lines);
void	free_split(char **matriz);
void	extantion(char *str);
void	free_all(t_vars *vars);
void	fill_matriz(char **matriz, char *s);
void	parse_map(t_vars *vars, char **file_lines);
void	validate_s(t_vars *vars);
void	check_map_borders(t_vars *vars);
char	*get_nextline(char *str, t_bytes *bit, t_vars *vars);
char	**ft_split(char *s);
char	**ft_split_color(char const *s, char c);
char	**alocate_matriz(int word);
char	*alocate_space(char *content, char *buffer);
char	**print_map(char *str, t_vars *vars);
char	*alocate_word(char *start, int len);
char	**replace_tabs_in_map(char **map, t_init *init);
char	**replace_spaces_in_one(char **map, t_init *init);
int		close_exit(void *noth);
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_player *player);
int		close_esc(t_vars *vars);
int		draw_loop(t_vars *vars);
int		last_arg(t_vars *vars);
int		is_map_closed(t_vars *vars);
int		check_top(t_vars *vars);
int		closed_map_aux(t_vars *vars);
int		delimeter(char c);
int		count_words(char *str);
int		verif_colors(t_vars *vars);
int		is_valid_color_format(t_vars *vars);
int		add_check_space(t_vars *vars);
int		extantion_xpm(char *str);
bool	touch(float px, float py, t_vars *vars);
float	fixed_dist(float y1, float y2, t_vars *vars);

#endif
