/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:27:40 by ctuiango          #+#    #+#             */
/*   Updated: 2024/08/13 13:31:19 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	receive(int signum)
{
	static int	cnt = 0;
	static char	res = 0;

	res <<= 1;
	res |= (signum == SIGUSR2);
	cnt++;
	if (cnt == 8)
	{
		ft_printf("%c", res);
		cnt = 0;
		res = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while (1)
	{
		pause();
	}
}
