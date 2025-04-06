/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:45:19 by cramos            #+#    #+#             */
/*   Updated: 2025/01/28 13:47:02 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static void	parse_texture(t_vars *vars, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		vars->north_texture = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		vars->south_texture = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		vars->west_texture = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		vars->east_texture = ft_strdup(line + 3);
}

static void	parse_color(t_vars *vars, char *line)
{
	int	r;
	int	g;
	int	b;

	if (ft_strncmp(line, "F ", 2) == 0)
	{
		verify_color_line(line, vars);
		ft_sscanf(line + 2, "%d,%d,%d", &r, &g, &b);
		vars->floor_color[0] = r;
		vars->floor_color[1] = g;
		vars->floor_color[2] = b;
		vars->floor_hex = (r << 16) | (g << 8) | b;
		vars->count_f++;
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		verify_color_line(line, vars);
		ft_sscanf(line + 2, "%d,%d,%d", &r, &g, &b);
		vars->ceiling_color[0] = r;
		vars->ceiling_color[1] = g;
		vars->ceiling_color[2] = b;
		vars->ceiling_hex = (r << 16) | (g << 8) | b;
		vars->count_c++;
	}
}

static void	parse_line(t_vars *vars, char *line)
{
	parse_texture(vars, line);
	parse_color(vars, line);
	if (ft_strncmp(line, "NO ", 3) != 0 && ft_strncmp(line, "SO ", 3) != 0
		&&ft_strncmp(line, "WE ", 3) != 0 && ft_strncmp(line, "EA ", 3) != 0
		&&ft_strncmp(line, "F ", 2) != 0 && ft_strncmp(line, "C ", 2) != 0)
	{
		if (vars->map == NULL)
			vars->map = malloc(sizeof(char *) * BUFFER_SIZE);
		vars->map[vars->map_count] = ft_strdup(line);
		vars->map_count++;
	}
}

void	parse_map(t_vars *vars, char **file_lines)
{
	char	*line;
	int		i;

	i = 0;
	vars->count_f = 0;
	vars->count_c = 0;
	while (file_lines[i] != NULL)
	{
		line = file_lines[i];
		if (ft_strlen(line) == 0)
		{
			i++;
			continue ;
		}
		parse_line(vars, line);
		i++;
	}
}
