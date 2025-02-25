/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:34:36 by ctuiango          #+#    #+#             */
/*   Updated: 2025/01/11 17:34:52 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static void	get_home(t_vars *vars)
{
	char	*equal;
	int		i;

	i = 0;
	while (vars->env[i] != NULL)
	{
		equal = ft_strchr(vars->env[i], '=');
		if (equal != NULL && ft_strncmp(vars->env[i], "HOME",
				equal - vars->env[i]) == 0 && (equal - vars->env[i]) == 4)
		{
			vars->home = equal + 1;
			return ;
		}
		i++;
	}
	vars->home = NULL;
}

void	cd(t_vars *vars)
{
	if (vars->matrix[1] == NULL)
		get_home(vars);
	else if (ft_strncmp(vars->matrix[1], "..", 2) == 0)
		vars->home = vars->matrix[1];
	else
		vars->home = vars->matrix[1];
	if (vars->home != NULL && chdir(vars->home) != 0)
	{
		perror("cd");
		vars->exit_status = 1;
	}
	else
		vars->exit_status = 0;
}

void	pwd(t_vars *vars)
{
	free(vars->input);
	vars->input = getcwd(NULL, 0);
	if (vars->input == NULL)
	{
		perror("Caminho não encontrado\n");
		vars->exit_status = 1;
		return ;
	}
	printf("%s\n", vars->input);
	vars->exit_status = 0;
}

void	env(t_vars *vars)
{
	t_env	*current;

	current = vars->env_ref;
	while (current != NULL)
	{
		printf("%s=%s\n", current->var, current->value);
		current = current->next;
	}
	vars->exit_status = 0;
}
