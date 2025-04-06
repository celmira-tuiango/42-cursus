/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_validate_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:31:05 by cramos            #+#    #+#             */
/*   Updated: 2025/03/03 11:31:46 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static int	check_color_format(char *line, int *on, int *numbers)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (line[i])
	{
		if (line[i] == ',')
			(*on)++;
		if (ft_isdigit(line[i]) && (i == 0 || !ft_isdigit(line[i - 1])))
			(*numbers)++;
		if (!ft_isdigit(line[i]) && line[i] != ',' && line[i] != ' ' && i > 1)
			error = 1;
		i++;
	}
	if (line[i - 1] == ',' || *on != 2 || *numbers != 3)
		error = 1;
	return (error);
}

void	verify_color_line(char *line, t_vars *vars)
{
	int	on;
	int	numbers;
	int	error;

	on = 0;
	numbers = 0;
	error = 0;
	if (line[0] != 'F' && line[0] != 'C')
		error = 1;
	if (check_color_format(line, &on, &numbers) == 1)
		error = 1;
	if (error)
	{
		printf("Erro: Cor do mapa invalido!\n");
		free_all(vars);
		free_split(vars->map);
		exit(1);
	}
}
