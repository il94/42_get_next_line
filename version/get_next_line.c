/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:01:42 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/05 16:20:11 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*result;
	int			i_buffer;
	int			i_result;
	int			size;

	if (!(result))
	{
		printf("malloc\n");
		result = calloc(BUFFER_SIZE * sizeof(char));
		i_buffer = 0;
		size += read(fd, buffer, BUFFER_SIZE);
	}
	else
	{
		i_buffer = strlen(result);
		printf("ibuffer = %d\n", i_buffer);
	}
	i_result = 0;
	size = 0;
	while (buffer[i_buffer] != '\n' && buffer[i_buffer] != EOF && buffer[i_buffer])
	{
		printf("c buffer = %c\n", buffer[i_buffer]);
		result[i_result] = buffer[i_buffer];
		i_buffer++;
		i_result++;
	}
	if (buffer[i_buffer] == '\n')
		result[i_result++] = '\n';
	return (result);
}

int	main(void)
{
	int		fd;
	int		i = 1;
	char	*str;

	fd = open("./file", O_RDONLY);
	if (fd > 0)
	{
		str = get_next_line(fd);
		printf("Line %d = %s", i++, str);
		str = get_next_line(fd);
		printf("Line %d = %s", i++, str);
		str = get_next_line(fd);
		printf("Line %d = %s", i++, str);
		str = get_next_line(fd);
		printf("Line %d = %s", i++, str);
		close(fd);
		free(str);
	}
	return (0);
}
