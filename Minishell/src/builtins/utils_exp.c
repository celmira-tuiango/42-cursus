/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:36:43 by ctuiango          #+#    #+#             */
/*   Updated: 2025/01/11 17:36:44 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int	is_valid_identifier(const char *var)
{
	if (!var || (!ft_isalpha(var[0]) && var[0] != '_'))
		return (0);
	while (*var)
	{
		if (!ft_isalnum(*var) && *var != '_')
			return (0);
		var++;
	}
	return (1);
}
