/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:36:23 by ctuiango          #+#    #+#             */
/*   Updated: 2024/09/13 13:36:27 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

char	**print_map(char *str)
{
	char	*cont_get;
	char	**cont_split;
	t_bytes	bit;

	cont_get = get_nextline(str, &bit);
	if (validate_n(cont_get) == 1)
	{
		ft_printf("Error\n Invalid Map\n");
		free(cont_get);
		exit(0);
	}
	cont_split = ft_split(cont_get);
	free(cont_get);
	return (cont_split);
}

static void	get_size(int fd, t_vars *vars)
{
	int		i;
	int		largura;
	int		altura;
	char	buffer;

	altura = 0;
	largura = 0;
	i = 0;
	vars->height = 0;
	vars->width = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		if (buffer != '\n')
		{
			if (i == 0)
				largura++;
		}
		if (buffer == '\n')
		{
			i = 1;
			altura++;
		}
	}
	vars->height = altura;
	vars->width = largura;
}

void	open_get_size(char *mapa, t_vars *vars)
{
	int	fd;

	fd = open(mapa, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nEmpty");
		exit(0);
	}
	get_size(fd, vars);
}
