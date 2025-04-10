/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:19:32 by cramos            #+#    #+#             */
/*   Updated: 2025/02/27 12:21:24 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_aux.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}
