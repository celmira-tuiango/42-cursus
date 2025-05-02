/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_four.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:39:54 by cramos            #+#    #+#             */
/*   Updated: 2025/02/26 12:39:59 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static char	**add_space_to_lines(char **map)
{
	char	**new_map;
	int		y;
	int		len;
	int		i;

	y = 0;
	while (map[y] != NULL)
		y++;
	new_map = malloc((y + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < y)
	{
		len = ft_strlen(map[i]);
		new_map[i] = malloc(len + 2);
		if (!new_map[i])
			return (NULL);
		ft_strcpy(new_map[i], map[i]);
		new_map[i][len] = ' ';
		new_map[i][len + 1] = '\0';
		i++;
	}
	new_map[y] = NULL;
	return (new_map);
}

static int	aux_closed_map(char **map, t_init *init)
{
	if ((init->t_y > 0 && init->t_x < ft_strlen(map[init->t_y - 1])
			&& map[init->t_y - 1][init->t_x] == '0') ||
		(map[init->t_y + 1] != NULL && init->t_x < ft_strlen(map[init->t_y + 1])
		&& map[init->t_y + 1][init->t_x] == '0') ||
		(init->t_x > 0 && map[init->t_y][init->t_x - 1] == '0') ||
		(init->t_x + 1 < ft_strlen(map[init->t_y])
		&& map[init->t_y][init->t_x + 1] == '0'))
	{
		return (1);
	}
	return (0);
}

static int	closed_map_space(char **map, t_init *init)
{
	init->t_y = 0;
	while (map[init->t_y] != NULL)
	{
		init->t_x = 0;
		while (map[init->t_y][init->t_x] != '\0')
		{
			if (map[init->t_y][init->t_x] == ' ' && map[init->t_y + 1] != NULL)
			{
				if (aux_closed_map(map, init))
					return (0);
			}
			init->t_x++;
		}
		init->t_y++;
	}
	return (1);
}

int	add_check_space(t_vars *vars)
{
	char	**map;
	char	**new_map;
	t_init	*init;

	init = malloc(sizeof(t_init));
	map = add_space_to_lines(vars->map);
	new_map = replace_tabs_in_map(map, init);
	free_split(vars->map);
	vars->map = replace_tabs_in_map(map, init);
	if (!closed_map_space(new_map, init))
	{
		free_split(map);
		free_split(new_map);
		free(init);
		return (0);
	}
	free_split(map);
	free_split(new_map);
	free(init);
	return (1);
}
