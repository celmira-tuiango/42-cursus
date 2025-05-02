/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:39:24 by ctuiango          #+#    #+#             */
/*   Updated: 2025/02/02 14:39:38 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static char	**allocate_map(int rows)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map[i] = NULL;
		i++;
	}
	map[rows] = NULL;
	return (map);
}

void	free_all(t_vars *vars)
{
	free_split(vars->file_lines);
	free(vars->north_texture);
	free(vars->south_texture);
	free(vars->west_texture);
	free(vars->east_texture);
}

void	initialize_vars(t_vars *vars)
{
	vars->map = allocate_map(BUFFER_SIZE);
	vars->north_texture = NULL;
	vars->south_texture = NULL;
	vars->west_texture = NULL;
	vars->east_texture = NULL;
	vars->file_lines = NULL;
	vars->map_count = 0;
	vars->height = 0;
	vars->width = 0;
	vars->floor_color[0] = -1;
	vars->floor_color[1] = -1;
	vars->floor_color[2] = -1;
	vars->ceiling_color[0] = -1;
	vars->ceiling_color[1] = -1;
	vars->ceiling_color[2] = -1;
	vars->count_c = 0;
	vars->count_f = 0;
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		extantion(av[1]);
		initialize_vars(&vars);
		vars.file_lines = print_map(av[1], &vars);
		parse_map(&vars, vars.file_lines);
		validate_s(&vars);
		init_vars(&vars);
		mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
		mlx_hook(vars.win, 3, 1L << 1, key_release, &vars.player);
		mlx_hook(vars.win, 17, 0, close_exit, &vars);
		mlx_loop_hook(vars.mlx, draw_loop, &vars);
		mlx_loop(vars.mlx);
	}
	else
		printf("error:\nParametros incorretos\n");
	return (0);
}
