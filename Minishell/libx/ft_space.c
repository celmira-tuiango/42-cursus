/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:40:11 by cramos            #+#    #+#             */
/*   Updated: 2025/01/11 17:40:13 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*ft_space(char *str)
{
	int		i;
	int		j;
	int		count;
	char	*new;

	if (!str)
		return (NULL);
	i = 0;
	count = 0;
	while (str[i++])
	{
		if (str[i] != ' ')
			count++;
	}
	new = malloc(sizeof(char) * (count + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			new[j++] = str[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}
