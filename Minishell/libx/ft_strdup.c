/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:42:16 by cramos            #+#    #+#             */
/*   Updated: 2025/01/11 17:42:17 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*ft_strdup(char *src)
{
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (src[len])
	{
		str[len] = src[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}
