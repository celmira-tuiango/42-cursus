/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:46:48 by cramos            #+#    #+#             */
/*   Updated: 2025/01/11 17:46:50 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*ft_trim(char *str)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	start = 0;
	if (!str)
		return (NULL);
	end = ft_strlen(str);
	while (str[start] && ft_isspace(str[start]))
		start++;
	while (end > start && ft_isspace(str[end - 1]))
		end--;
	trimmed = malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	ft_strncpy(trimmed, &str[start], end - start);
	trimmed[end - start] = '\0';
	return (trimmed);
}
