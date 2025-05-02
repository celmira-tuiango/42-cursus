/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nextline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:57:51 by cramos            #+#    #+#             */
/*   Updated: 2025/01/28 12:57:57 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static void	close_check(char *content, t_vars *vars)
{
	free(content);
	free_split(vars->map);
	exit(1);
}

static void	total_bytes(t_bytes *bit, char *content, int fd)
{
	if (bit->total_bytess > 1024)
	{
		printf("Error\nMap too big!\n");
		free(content);
		close(fd);
		exit(1);
	}
}

static void	extra(t_vars *vars)
{
	perror("Error\n");
	free(vars->map);
	exit(1);
}

char	*get_nextline(char *str, t_bytes *bit, t_vars *vars)
{
	int		bytes;
	int		fd;
	char	buffer[1025];
	char	*content;

	content = 0;
	bit->total_bytess = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		extra(vars);
	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		bit->total_bytess += bytes;
		total_bytes(bit, content, fd);
		content = alocate_space(content, buffer);
		bytes = read(fd, buffer, 1024);
	}
	close(fd);
	if (bytes < 0 || content == NULL || content[0] == '\0')
		close_check(content, vars);
	return (content);
}
