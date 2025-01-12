/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:40:41 by cramos            #+#    #+#             */
/*   Updated: 2025/01/11 17:40:42 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

static int	deli(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	**ft_split(char *str)
{
	int		x;
	int		y;
	int		l;
	char	**m;

	y = 0;
	l = 0;
	while (*str && deli(*str))
		str++;
	while (str[l])
		l++;
	m = malloc(sizeof(char *) * (l + 1));
	while (*str)
	{
		x = 0;
		m[y] = malloc(sizeof(char *) * (l + 1));
		while (*str && !deli(*str))
			m[y][x++] = *(str++);
		while (*str && deli(*str))
			str++;
		m[y++][x] = '\0';
	}
	m[y] = NULL;
	return (m);
}
