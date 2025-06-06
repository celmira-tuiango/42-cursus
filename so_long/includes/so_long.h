/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:28:04 by ctuiango          #+#    #+#             */
/*   Updated: 2024/09/13 12:33:17 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL 64

# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_vars
{
	int		height;
	int		width;
	int		h_img;
	int		w_img;
	int		pos_x;
	int		pos_y;
	int		count_collects;
	int		count_steps;
	int		b_step;
	int		start_point_x;
	int		start_point_y;
	void	*mlx;
	void	*win;
	void	*player;
	void	*wall;
	void	*way;
	void	*exit;
	void	*collect;
	char	**map;
	char	**map_copy;
}t_vars;

typedef struct s_bytes
{
	int	total_bytess;
}t_bytes;

int		ft_strlen(char *str);
int		move_player(int keycode, t_vars *vars);
int		delimeter(char c);
int		close_exit(void *noth);
int		close_esc(int keycode, t_vars *vars);
int		validate_n(char *str);
int		strchr_on_matrix(char **matrix, char c);
int		count_words(char *str);
void	fill_matriz(char **matriz, char *s);
void	free_split(char **matriz);
void	find_player(t_vars *vars);
void	is_retangle(t_vars *vars);
void	count_collect(t_vars *vars);
void	update_positions(t_vars *vars, int x, int y);
void	render_map(t_vars *vars, char **map);
void	destroy_image(t_vars *vars);
void	close_v(t_vars *vars);
void	set_images(t_vars *vars);
void	validations(t_vars *vars);
void	extantion(char *str);
void	playable(t_vars *vars);
void	flood_fill(int x, int y, t_vars *vars);
void	flood(int x, int y, t_vars *vars);
void	open_get_size(char *mapa, t_vars *vars);
char	*alocate_word(char *start, int len);
char	**print_map(char *str);
char	**alocate_matriz(int word);
char	*get_nextline(char *str, t_bytes *bit);
char	*alocate_space(char *content, char *buffer);
char	*ft_strdup(char *str);
char	*ft_strcat(char *dest, char *str);
char	**ft_split(char *s);

#endif
