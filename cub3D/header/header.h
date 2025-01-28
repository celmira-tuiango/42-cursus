#ifndef HEADER_H
# define HEADER_H

# define WIDTH 1280
# define HEIGTH 720

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

typedef struct  s_vars
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *data;
    int    bpp;
    int    size_line;
    int endian;

} t_vars;

#endif
