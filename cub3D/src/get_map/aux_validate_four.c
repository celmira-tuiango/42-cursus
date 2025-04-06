/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_validate_four.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:51:27 by cramos            #+#    #+#             */
/*   Updated: 2025/03/03 11:51:53 by cramos           ###   ########.fr       */
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
	init->tab_count = 0;
	init->j = 0;
	while (init->j < init->len)
	{
		if (map[init->i][init->j] == '\t')
			init->tab_count++;
		init->j++;
	}
	init->new_len = init->len + (init->tab_count * (TAB_SIZE - 1));
	init->new_map[init->i] = malloc(init->new_len + 1);
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
		if (map[init->i][init->j] == '\t')
		{
			ft_memset(&init->new_map[init->i][init->x], ' ', TAB_SIZE);
			init->x += TAB_SIZE;
		}
		else
			init->new_map[init->i][init->x++] = map[init->i][init->j];
		init->j++;
	}
}

char	**replace_tabs_in_map(char **map, t_init *init)
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
	return (init->new_map);
}
