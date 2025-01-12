/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:46:20 by cramos            #+#    #+#             */
/*   Updated: 2025/01/11 17:46:21 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;
	size_t	sub;

	if (!s)
		return (0);
	slen = ft_strlen2(s);
	sub = 0;
	if (start < slen)
		sub = slen - start;
	if (sub > len)
		sub = len;
	new = (char *)malloc(sizeof(char) * (sub + 1));
	if (!new)
		return (0);
	ft_strlcpy(new, s + start, sub + 1);
	return (new);
}
