/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyes <ilyes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:05:03 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/22 18:08:26 by ilyes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			size_read;

	line = NULL;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin_gnl(line, buffer[fd]);
	size_read = BUFFER_SIZE;
	while (!(is_end_of_line(line) || size_read != BUFFER_SIZE))
	{
		size_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (size_read < 0)
			return (NULL);
		buffer[fd][size_read] = '\0';
		line = ft_strjoin_gnl(line, buffer[fd]);
	}
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	else
		get_line(line, buffer[fd]);
	return (line);
}
