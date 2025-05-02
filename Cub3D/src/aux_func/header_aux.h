/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_aux.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:44:14 by cramos            #+#    #+#             */
/*   Updated: 2025/02/04 12:48:38 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_AUX_H
# define HEADER_AUX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>

void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(char *src);
char	*ft_strcat(char *dest, char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_sscanf(const char *str, const char *format, ...);
int		handle_format_specifier(const char **s, \
	const char **format, va_list *args);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_atoi(const char *str);

#endif
