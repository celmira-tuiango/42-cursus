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

void    draw_square(int x, int y, int size, int color, t_vars *vars)
{
    for(int i = 0; i < size; i++)
        put_pixel(x + i, y, color, vars);
    for(int i = 0; i < size; i++)
        put_pixel(x, y + i, color, vars);
    for(int i = 0; i < size; i++)
        put_pixel(x + size, y + i, color, vars);
    for(int i = 0; i < size; i++)
        put_pixel(x + i, y + size, color, vars);
}

void    draw_map(t_vars *vars)
{
    char **map = vars->map;
    int color = 0x0000FF;
    for (int y = 0; map[y]; y++)
        for (int x  = 0; map[y][x]; x++)
            if (map[y][x] == '1')
                draw_square(x * BLOCK, y * BLOCK, BLOCK, color, vars);
}

void    clear_image(t_vars *vars)
{
    for(int y = 0; y < HEIGTH; y++)
        for(int x = 0; x < WIDTH; x++)
            put_pixel(x, y, 0, vars);
}

char    **get_map(void)
{
    char **map = malloc(sizeof(char *) * 11);
    map[0] = "111111111111111";
    map[1] = "100000000000001";
    map[2] = "100000000000001";
    map[3] = "100000100000001";
    map[4] = "100000000000001";
    map[5] = "100000010000001";
    map[6] = "100001000000001";
    map[7] = "100000000000001";
    map[8] = "100000000000001";
    map[9] = "111111111111111";
    map[10] = NULL;
    return (map);
}

void    init_vars(t_vars *vars)
{
    init_player(&vars->player);
    vars->map = get_map();
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGTH, "Cub3D");
    vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGTH);
    vars->data = mlx_get_data_addr(vars->img, &vars->bpp, &vars->size_line, &vars->endian);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

bool    touch(float px, float py, t_vars *vars)
{
    int x = px / BLOCK;
    int y = py / BLOCK;

    if (vars->map[y][x] == '1')
        return (true);
    return (false);
}

float   distance(float x, float y)
{
    return (sqrt(x * x + y * y));
}

float   fixed_dist(float x1, float y1, float x2, float y2, t_vars *vars)
{
    float delta_x = x2 - x1;
    float dela_y = y2 - y1;
    float angle = atan2(dela_y, delta_x) - vars->player.angle;
    float fix_dist = distance(delta_x, dela_y) * cos(angle);
    return (fix_dist);
}

void    draw_line(t_player *player, t_vars *vars, float start_x, int i)
{
    float cos_angle = cos(start_x);
    float sin_angle = sin(start_x);
    float ray_x = player->x;
    float ray_y = player->y;

    while (!touch(ray_x, ray_y, vars))
    {
        if (DEBUG)
            put_pixel(ray_x, ray_y, 0xFF0000, vars);
        ray_x += cos_angle;
        ray_y += sin_angle;     
    }
    if (!DEBUG)
    {

        float dist = fixed_dist(player->x, player->y, ray_x, ray_y, vars);
        float height = (BLOCK / dist) * (WIDTH / 2);
        int start_y = (HEIGTH - height) / 2;
        int end = start_y + height;
        while (start_y < end)
        {
            put_pixel(i, start_y, 255, vars);
            start_y++;
        }
    }
    
}

int draw_loop(t_vars *vars)
{
    t_player    *player = &vars->player;
    move_player(player);
    clear_image(vars);
    if (DEBUG)
    {

        draw_square(player->x, player->y, 10, 0x00FF00, vars);
        draw_map(vars);
    }
    
    float fraction = PI / 3 / WIDTH;
    float start_x = player->angle - PI / 6;
    int i = 0;
    while (i < WIDTH)
    {
        draw_line(player, vars, start_x, i);
        start_x += fraction;
        i++;
    }

    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
    return (0); 
}

int	main(void)
{
    t_vars  vars;

    init_vars(&vars);
    mlx_hook(vars.win, 2, 1L<<0, key_press, &vars.player);
    mlx_hook(vars.win, 3, 1L<<1, key_release, &vars.player);
    mlx_loop_hook(vars.mlx, draw_loop, &vars);
    mlx_loop(vars.mlx);
    return (0);
}
