/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sncat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:47:10 by cramos            #+#    #+#             */
/*   Updated: 2025/01/11 17:47:13 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*sncat(char *dest, const char *src, size_t n)
{
	char	*original_dest;

	original_dest = dest;
	while (*dest)
		dest++;
	while (n-- > 0 && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (original_dest);
}
