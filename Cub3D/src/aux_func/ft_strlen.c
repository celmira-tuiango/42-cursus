/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:43:44 by cramos            #+#    #+#             */
/*   Updated: 2025/01/11 17:43:45 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_aux.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}
