/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:36:29 by ctuiango          #+#    #+#             */
/*   Updated: 2025/01/11 17:36:35 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static void	free_env_node(t_env *node)
{
	if (node)
	{
		free(node->var);
		free(node->value);
		free(node);
	}
}

static t_env	*unset_env(t_env *head, char *var)
{
	t_env	*current;
	t_env	*previous;

	current = head;
	previous = NULL;
	if (!head || !var)
		return (head);
	while (current)
	{
		if (strcmp(current->var, var) == 0)
		{
			if (previous)
				previous->next = current->next;
			else
				head = current->next;
			free_env_node(current);
			return (head);
		}
		previous = current;
		current = current->next;
	}
	return (head);
}

t_env	*ft_unset(t_env *head, char **vars)
{
	int	i;

	i = 0;
	if (!head || !vars)
		return (head);
	while (vars[i])
	{
		head = unset_env(head, vars[i]);
		i++;
	}
	return (head);
}
