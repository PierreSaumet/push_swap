/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_reinit_buffer(ssize_t pos_end_line, char *buffer)
{
	size_t	i;
	ssize_t	start_new_line;

	i = 0;
	start_new_line = pos_end_line + 1;
	while (buffer[start_new_line] != '\0')
	{
		buffer[i] = buffer[start_new_line];
		start_new_line++;
		i++;
	}
	buffer[i] = '\0';
}

char	*ft_create_line(char *str, char **line)
{
	size_t	len;
	char	*s;

	s = *line;
	len = ft_strlen_gnl(str);
	if (s == NULL)
		s = ft_strndup_gnl(str, len);
	else
		s = ft_strjoin_gnl(s, str);
	return (s);
}

int		ft_get_line(char **line, char *buffer, int ret_search, int ret_read)
{
	char	*tmp;

	buffer[ret_read] = '\0';
	if (ret_search >= 0)
	{
		tmp = ft_strndup_gnl(buffer, ret_search);
		*line = ft_create_line(tmp, line);
		ft_reinit_buffer(ret_search, buffer);
		free(tmp);
		return (1);
	}
	else
	{
		*line = ft_create_line(buffer, line);
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		ret_read;
	ssize_t		ret_search;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strdup_gnl(buffer);
	if ((ret_search = ft_search_line(buffer)) >= 0)
	{
		free(*line);
		(*line) = ft_strndup_gnl(buffer, ret_search);
		ft_reinit_buffer(ret_search, buffer);
		return (1);
	}
	while ((ret_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		ret_search = ft_search_line(buffer);
		if (ft_get_line(line, buffer, ret_search, ret_read) == 1)
			return (1);
	}
	if (ret_read == 0)
		return (0);
	return (-1);
}
