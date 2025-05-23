/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_imagens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:08:37 by ctuiango          #+#    #+#             */
/*   Updated: 2025/02/15 13:08:38 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static void	aux_load_textures(t_vars *vars)
{
	vars->textures[0] = mlx_xpm_file_to_image(vars->mlx, vars->north_texture,
			&vars->tex_width, &vars->tex_height);
	vars->textures[1] = mlx_xpm_file_to_image(vars->mlx, vars->south_texture,
			&vars->tex_width, &vars->tex_height);
	vars->textures[2] = mlx_xpm_file_to_image(vars->mlx, vars->west_texture,
			&vars->tex_width, &vars->tex_height);
	vars->textures[3] = mlx_xpm_file_to_image(vars->mlx, vars->east_texture,
			&vars->tex_width, &vars->tex_height);
}

void	load_textures(t_vars *vars)
{
	int	i;

	i = 0;
	if (!vars->north_texture || !vars->south_texture
		|| !vars->west_texture || !vars->east_texture)
	{
		printf("error: ao carregar textura \n");
		close_exit(vars);
	}
	aux_load_textures(vars);
	while (i < 4)
	{
		if (!vars->textures[i])
		{
			printf("error: ao carregar textura %d\n", i);
			close_exit(vars);
		}
		vars->tex_data[i] = mlx_get_data_addr(vars->textures[i],
				&vars->tex_bpp[i], &vars->tex_sl[i], &vars->tex_end[i]);
		i++;
	}
	vars->block = vars->tex_height;
}

void	render_texture_column(t_vars *vars, int texture_index, \
	int column, int start_y)
{
	int		y;
	int		bpp;
	int		sl;
	char	*data;

	bpp = vars->tex_bpp[texture_index];
	sl = vars->tex_sl[texture_index];
	data = vars->tex_data[texture_index];
	y = start_y;
	while (y < vars->end)
	{
		vars->tex_y = ((y - start_y) * vars->tex_height)
			/ (vars->end - start_y);
		if (vars->tex_y >= vars->tex_height)
			vars->tex_y = vars->tex_height - 1;
		vars->pix_color = *(int *)(data + (vars->tex_y
					* sl + vars->tex_x * (bpp / 8)));
		vars->pix_color = mlx_get_color_value(vars->mlx, vars->pix_color);
		put_pixel(column, y, vars->pix_color, vars);
		y++;
	}
}
