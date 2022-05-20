/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:05:03 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/20 15:56:06 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*line;
	int		size_read;
	
	// printf("buffer at start: |%s|", buffer);
	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	// if (buffer[0])
	{
		line = ft_strjoin_gnl(line, buffer);
		// clean_line(line, buffer);
	}
	size_read = BUFFER_SIZE;
	while (!(is_end_of_line(line, size_read)))
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		// printf("size_read = %d && buffer = %s\n", size_read, buffer);
		if (size_read < 0)
			return (NULL);
		line = ft_strjoin_gnl(line, buffer);
		// if (size_read == 0)
		// 	break ;
		// stash = ft_strjoin_gnl(stash, buffer, size_read);
	}
	// printf("buffer before cleaning: %s", buffer);
	clean_line(line, buffer);
	// printf("buffer after cleaning %s", buffer);
	return (line);
}
