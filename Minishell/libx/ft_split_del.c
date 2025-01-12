/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:40:51 by cramos            #+#    #+#             */
/*   Updated: 2025/01/11 17:40:54 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

static int	deli(char c, const char *delimiters)
{
	while (*delimiters)
	{
		if (c == *delimiters)
			return (1);
		delimiters++;
	}
	return (0);
}

char	**ft_split_del(char *str, const char *delimiters)
{
	int		x;
	int		y;
	int		l;
	char	**m;

	l = 0;
	y = 0;
	while (*str && deli(*str, delimiters))
		str++;
	while (str[l])
		l++;
	m = malloc(sizeof(char *) * (l + 1));
	while (*str)
	{
		x = 0;
		m[y] = malloc(sizeof(char) * (l + 1));
		while (*str && !deli(*str, delimiters))
			m[y][x++] = *(str++);
		while (*str && deli(*str, delimiters))
			str++;
		m[y][x] = '\0';
		y++;
	}
	m[y] = NULL;
	return (m);
}
