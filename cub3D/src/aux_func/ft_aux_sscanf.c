/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_sscanf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:29:56 by cramos            #+#    #+#             */
/*   Updated: 2025/02/28 12:34:45 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_aux.h"

static int	read_int(const char **s)
{
	int	num;
	int	negative;

	num = 0;
	negative = 0;
	if (**s == '-')
	{
		negative = 1;
		(*s)++;
	}
	while (**s && ft_isdigit(**s))
	{
		num = num * 10 + (**s - '0');
		(*s)++;
	}
	if (negative == 1)
		return (-num);
	return (num);
}

static float	process_decimal(const char **s, float num)
{
	int	divisor;

	divisor = 10;
	while (ft_isdigit(**s))
	{
		num += (**s - '0') / (float) divisor;
		divisor *= 10;
		(*s)++;
	}
	return (num);
}

static float	read_float(const char **s)
{
	float	num;
	int		negative;

	num = 0.0;
	negative = 0;
	if (**s == '-')
	{
		negative = 1;
		(*s)++;
	}
	while (ft_isdigit(**s))
	{
		num = num * 10 + (**s - '0');
		(*s)++;
	}
	if (**s == '.')
	{
		(*s)++;
		num = process_decimal(s, num);
	}
	if (negative == 1)
		return (-num);
	return (num);
}

static void	read_string(const char **s, char *dest)
{
	while (**s && !ft_isspace(**s))
	{
		*dest = **s;
		dest++;
		(*s)++;
	}
	*dest = '\0';
}

int	handle_format_specifier(const char **s, const char **format, va_list *args)
{
	char	*v;
	float	*pp;
	int		*p;
	int		count;

	count = 0;
	if (**format == 'd')
	{
		p = va_arg(*args, int *);
		*p = read_int(s);
		count++;
	}
	else if (**format == 'f')
	{
		pp = va_arg(*args, float *);
		*pp = read_float(s);
		count++;
	}
	else if (**format == 's')
	{
		v = va_arg(*args, char *);
		read_string(s, v);
		count++;
	}
	return (count);
}
