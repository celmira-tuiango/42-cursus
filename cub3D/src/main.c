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

int	main(void)
{
	t_vars	vars;

	init_vars(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars.player);
	mlx_hook(vars.win, 17, 0, close_exit, &vars);
	mlx_loop_hook(vars.mlx, draw_loop, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
