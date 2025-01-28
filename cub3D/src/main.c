#include "../header/header.h"

// my own put_pixel
void    put_pixel(int x, int y, int color, t_vars *vars)
{
    if (x >= WIDTH || y >= HEIGTH || x < 0 || y < 0)
        return ;
    int index = y * vars->size_line + x * vars->bpp / 8;
    vars->data[index] = color & 0xFF;
    vars->data[index + 1] = (color >> 8) & 0xFF;
    vars->data[index + 2] = (color >> 16) & 0xFF;
}

void    init_vars(t_vars *vars)
{
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGTH, "Cub3D");
    vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGTH);
    vars->data = mlx_get_data_addr(vars->img, &vars->bpp, &vars->size_line, &vars->endian);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

void    draw_square(int x, int y, int size, int color, t_vars *vars)
{
    for(int i = 0; i < size; i++)
        put_pixel(x + i, y, color, vars);
    for(int i = 0; i < size; i++)
        put_pixel(x, y + i, color, vars);
    for(int i = 0; i < size; i++)
        put_pixel(x + size, y, color, vars);
    for(int i = 0; i < size; i++)
        put_pixel(x, y + size, color, vars);
}

int	main(void)
{
    t_vars  vars;

    init_vars(&vars);
    draw_square(WIDTH / 2, HEIGTH / 2, 10, 0x00FF00, &vars);
    mlx_loop(vars.mlx);
    return (0);
}
