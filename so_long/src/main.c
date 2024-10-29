/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:34:57 by ctuiango          #+#    #+#             */
/*   Updated: 2024/09/13 12:35:00 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void	initialazing(t_vars *vars, char *str)
{
	extantion(str);
	vars->map = print_map(str);
	vars->map_copy = print_map(str);
	open_get_size(str, vars);
	validations(vars);
	is_retangle(vars);
	playable(vars);
}

static	void	dimention(t_vars *vars)
{
	int	altura;
	int	largura;

	altura = vars->height * PIXEL;
	largura = vars->width * PIXEL;
	if (largura >= 1920 || altura >= 1080)
	{
		ft_printf("Error\nMap Too big\n");
		close_v(vars);
	}
}

static void	destroy_all(t_vars *vars)
{
	free_split(vars->map);
	destroy_image(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		initialazing(&vars, av[1]);
		dimention(&vars);
		ft_printf("\n\n********************START GAME********************\n\n");
		vars.count_steps = 0;
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx,
				vars.width * PIXEL, vars.height * PIXEL, "so_long");
		mlx_hook(vars.win, 17, 0, close_exit, &vars);
		count_collect(&vars);
		set_images(&vars);
		render_map(&vars, vars.map);
		mlx_hook(vars.win, 2, 1L << 0, move_player, &vars);
		mlx_loop(vars.mlx);
		destroy_all(&vars);
	}
	return (0);
}
