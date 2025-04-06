/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:41:56 by cramos            #+#    #+#             */
/*   Updated: 2025/03/22 13:42:01 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static int	aux_one(t_init *init, char **map)
{
	init->y = 0;
	while (map[init->y] != NULL)
		init->y++;
	init->new_map = malloc((init->y + 1) * sizeof(char *));
	if (!init->new_map)
		return (1);
	init->i = 0;
	return (0);
}

static int	aux_two(t_init *init, char **map)
{
	init->len = ft_strlen(map[init->i]);
	init->new_map[init->i] = malloc(init->len + 1);
	if (!init->new_map[init->i])
		return (1);
	init->x = 0;
	init->j = 0;
	return (0);
}

static void	aux_three(t_init *init, char **map)
{
	while (init->j < init->len)
	{
		if (map[init->i][init->j] == ' ')
			init->new_map[init->i][init->x] = '1';
		else
			init->new_map[init->i][init->x] = map[init->i][init->j];
		init->x++;
		init->j++;
	}
}

char	**replace_spaces_in_one(char **map, t_init *init)
{
	if (!init)
		return (NULL);
	if (aux_one(init, map))
		return (NULL);
	while (init->i < init->y)
	{
		if (aux_two(init, map))
			return (NULL);
		aux_three(init, map);
		init->new_map[init->i][init->x] = '\0';
		init->i++;
	}
	init->new_map[init->y] = NULL;
	free_split(map);
	return (init->new_map);
}
