/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:15:04 by cramos            #+#    #+#             */
/*   Updated: 2025/02/04 08:57:50 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

void	valid_elem_aux(t_vars *vars, t_init *init, int s, int c)
{
	if (c == 1)
	{
		if (s != 0)
		{
			printf("Error: Strange element\n");
			free_split(vars->map);
			free_all(vars);
			free(init);
			exit(1);
		}
	}
	if (c == 2)
	{
		free_all(vars);
		free(init);
		free_split(vars->map);
		exit(1);
	}
}

static void	valid_elem(t_vars *vars, t_init *init)
{
	int	y;
	int	s;
	int	x;

	y = 0;
	s = 0;
	while (vars->map[y] != NULL)
	{
		x = 0;
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][x] != 'S' && vars->map[y][x] != 'N' &&
			vars->map[y][x] != 'E' && vars->map[y][x] != 'W' &&
			vars->map[y][x] != '1' && vars->map[y][x] != '0' &&
			vars->map[y][x] != ' ' && vars->map[y][x] != '\t')
				s++;
			x++;
		}
		y++;
	}
	valid_elem_aux(vars, init, s, 1);
}

static int	validate_s_aux(t_vars *vars)
{
	int	y;
	int	s;
	int	x;

	y = 0;
	s = 0;
	while (vars->map[y] != NULL)
	{
		x = 0;
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][x] == 'S' || vars->map[y][x] == 'N' ||
				vars->map[y][x] == 'E' || vars->map[y][x] == 'W')
				s++;
			x++;
		}
		y++;
	}
	return (s);
}

static int	check_xpm(t_vars *vars)
{
	if (!vars->north_texture || extantion_xpm(vars->north_texture))
		return (0);
	if (!vars->south_texture || extantion_xpm(vars->south_texture))
		return (0);
	if (!vars->west_texture || extantion_xpm(vars->west_texture))
		return (0);
	if (!vars->east_texture || extantion_xpm(vars->east_texture))
		return (0);
	return (1);
}

void	validate_s(t_vars *vars)
{
	int		s;
	t_init	*init;

	init = malloc(sizeof(t_init));
	s = validate_s_aux(vars);
	valid_elem(vars, init);
	if (s != 1 || !is_map_closed(vars) || !add_check_space(vars)
		|| !closed_map_aux(vars)
		|| !check_top(vars) || !last_arg(vars))
	{
		printf("Erro: Mapa invalido!\n");
		free_all(vars);
		free_split(vars->map);
		free(init);
		exit(1);
	}
	if (!verif_colors(vars) || !check_xpm(vars))
	{
		printf("Erro: Argumento do mapa invalido!\n");
		valid_elem_aux(vars, init, 0, 2);
	}
	vars->map = replace_spaces_in_one(vars->map, init);
	free(init);
}
