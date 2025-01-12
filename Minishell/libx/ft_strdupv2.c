/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupv2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:42:28 by cramos            #+#    #+#             */
/*   Updated: 2025/01/11 17:42:30 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*ft_strdupv2(char *src)
{
	int		len;
	char	*str;

	len = 0;
	while (src[len] == ' ')
		len++;
	while (src[len])
		len++;
	str = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (src[len] == ' ')
		len++;
	while (src[len])
	{
		str[len] = src[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}
