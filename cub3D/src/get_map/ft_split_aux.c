/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:56:50 by cramos            #+#    #+#             */
/*   Updated: 2025/01/28 12:56:55 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int	delimeter(char c)
{
	return (c == '\n');
}

int	count_words(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && delimeter(*str))
			str++;
		if (*str && !delimeter(*str))
		{
			cnt++;
			while (*str && !delimeter(*str))
				str++;
		}
	}
	return (cnt);
}
