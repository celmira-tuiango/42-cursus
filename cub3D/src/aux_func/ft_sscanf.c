/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:29:23 by cramos            #+#    #+#             */
/*   Updated: 2025/01/31 14:51:16 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_aux.h"

static void	skip_spaces(const char **s)
{
	while (**s && ft_isspace(**s))
		(*s)++;
}

static int	process_format(const char **s, const char **format, va_list *args)
{
	int	count;

	count = 0;
	while (**format && **s)
	{
		if (**format == '%')
		{
			(*format)++;
			count += handle_format_specifier(s, format, args);
		}
		else if (ft_isspace(**format))
			skip_spaces(s);
		else
		{
			if (**format != **s)
				break ;
			(*s)++;
		}
		(*format)++;
	}
	return (count);
}

int	ft_sscanf(const char *str, const char *format, ...)
{
	va_list		args;
	const char	*s;
	int			count;

	va_start(args, format);
	s = str;
	count = process_format(&s, &format, &args);
	va_end(args);
	return (count);
}
