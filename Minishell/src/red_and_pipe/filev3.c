/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filev3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:42:04 by ctuiango          #+#    #+#             */
/*   Updated: 2025/01/11 17:42:05 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

size_t	count_digit_base(unsigned long n, unsigned int base)
{
	size_t	counter;

	counter = 1;
	while (n / base != 0)
	{
		counter++;
		n = n / base;
	}
	return (counter);
}

char	*gen_tmpfile_name(int cmd_nbr)
{
	int				digits;
	char			*tmpfile_name;
	char			*tmpfile_nbr;
	unsigned int	buf_size;

	tmpfile_nbr = ft_itoa(cmd_nbr);
	digits = count_digit_base(cmd_nbr, 10);
	buf_size = 6 + digits;
	tmpfile_name = malloc(buf_size);
	ft_memmove(tmpfile_name, "/tmp/", 6);
	ft_strlcat(tmpfile_name, tmpfile_nbr, buf_size);
	free(tmpfile_nbr);
	return (tmpfile_name);
}

void	write_and_close(int fd)
{
	write(fd, "\0", 1);
	close(fd);
}
