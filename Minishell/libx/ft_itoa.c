/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:39:21 by cramos            #+#    #+#             */
/*   Updated: 2025/01/11 17:39:23 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

static int	nbnb(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*is_zero(int nb, char *str)
{
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	nb;

	nb = n;
	i = nbnb(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (is_zero(nb, str))
		return (str);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		str[i--] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (str);
}
