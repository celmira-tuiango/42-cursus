/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxilary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:48:56 by ctuiango          #+#    #+#             */
/*   Updated: 2024/08/14 15:02:44 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strdup(char *str)
{
	int		len;
	char	*cpy;

	len = 0;
	while (str[len])
		len++;
	cpy = malloc(sizeof(char) * (len + 2));
	len = 0;
	while (str[len])
	{
		cpy[len] = str[len];
		len++;
	}
	cpy[len] = '\n';
	len++;
	cpy[len] = '\0';
	return (cpy);
}

int	ft_atoi(char *s)
{
	int	res;
	int	l;

	l = 0;
	res = 0;
	while (s[l] >= '0' && s[l] <= '9')
	{
		res = res * 10 + s[l] - '0';
		l++;
	}
	return (res);
}
