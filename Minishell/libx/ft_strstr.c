/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:45:01 by cramos            #+#    #+#             */
/*   Updated: 2025/01/11 17:45:05 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*ft_strstr(char *haystack, char *needle)
{
	char	*h;
	char	*n;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			h = haystack;
			n = needle;
			while (*n && *h == *n)
			{
				h++;
				n++;
			}
			if (*n == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
