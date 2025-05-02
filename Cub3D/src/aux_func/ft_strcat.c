/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:56:35 by cramos            #+#    #+#             */
/*   Updated: 2025/01/28 12:56:42 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_aux.h"

char	*ft_strcat(char *dest, char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (dest[len])
		len++;
	while (str[i])
	{
		dest[len] = str[i];
		len++;
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
