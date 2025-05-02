/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:57:28 by cramos            #+#    #+#             */
/*   Updated: 2025/01/28 12:57:40 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static int	get_valid_indexes(char *str, int *end)
{
	int	k;
	int	i;

	k = 0;
	while (str[k] && str[k + 1] && str[k + 2] && str[k + 3])
	{
		if (str[k] == '1' && str[k + 1] == '1'
			&& str[k + 2] == '1' && str[k + 3] == '1')
			break ;
		k++;
	}
	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (i > 0)
	{
		if (str[i] == '1')
			break ;
		i--;
	}
	*end = i;
	return (k);
}

static void	validate_n(char *str, t_vars *vars)
{
	int	k;
	int	i;

	k = get_valid_indexes(str, &i);
	while (k < i)
	{
		if (k + 1 < i)
		{
			if (str[k] == '\n' && str[k + 1] == '\n')
			{
				printf("error: mapa invalido\n");
				free(str);
				free_split(vars->map);
				exit(0);
			}
		}
		k++;
	}
}

char	*alocate_space(char *content, char *buffer)
{
	char	*new_var;
	char	*temp;

	temp = content;
	if (content == NULL)
		new_var = ft_strdup(buffer);
	else
		new_var = ft_strcat(ft_strdup(content), buffer);
	if (temp)
		free(temp);
	return (new_var);
}

static void	file_empty(char *str, t_vars *vars)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
			a++;
		i++;
	}
	if (a == 0)
	{
		printf("Error: Empty file!\n");
		free(str);
		free_split(vars->map);
		exit(1);
	}
}

char	**print_map(char *str, t_vars *vars)
{
	char	*cont_get;
	char	**cont_split;
	t_bytes	bit;

	cont_get = get_nextline(str, &bit, vars);
	file_empty(cont_get, vars);
	validate_n(cont_get, vars);
	cont_split = ft_split(cont_get);
	free(cont_get);
	return (cont_split);
}
