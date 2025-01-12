/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:40:23 by cramos            #+#    #+#             */
/*   Updated: 2025/01/11 17:40:24 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	handle_quotes(const char **s)
{
	if (**s == '\'')
	{
		(*s)++;
		while (**s != '\'')
			(*s)++;
	}
	if (**s == '\"')
	{
		(*s)++;
		while (**s != '\"')
			(*s)++;
	}
}

int	ft_count_args(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == 32)
			++s;
		while (*s > 32 && *s < 127)
		{
			handle_quotes(&s);
			++s;
		}
		count++;
	}
	return (count);
}

void	handle_quote(const char **s, int *point)
{
	if (**s == '\'')
	{
		(*s)++;
		(*point)++;
		while (**s != '\'')
		{
			(*s)++;
			(*point)++;
		}
	}
	if (**s == '\"')
	{
		(*s)++;
		(*point)++;
		while (**s != '\"')
		{
			(*s)++;
			(*point)++;
		}
	}
}
