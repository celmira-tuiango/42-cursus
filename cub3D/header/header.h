#ifndef HEADER_H
# define HEADER_H

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

# define PI 3.14159265359

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_player
{
    float   x;
    float   y;
    float   angle;

    bool    key_up;
    bool    key_down;
    bool    key_left;
    bool    key_right;

    bool    left_rotate;
    bool    right_rotate;
} t_player;

typedef struct  s_vars
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *data;
    char    **map;
    int    bpp;
    int    size_line;
    int endian;
    t_player    player;
} t_vars;


void    init_player(t_player *player);
void    move_player(t_player *player);
int key_press(int keycode, t_player *player);
int key_release(int keycode, t_player *player);

#endif
