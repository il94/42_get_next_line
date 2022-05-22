/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyes <ilyes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:01:42 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/21 23:46:25 by ilyes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line5.h"

int	is_end_of_line(char *str, int size_read)
{
	if (str == NULL || size_read != BUFFER_SIZE
		|| !ft_strchr_gnl(str, '\n'))
		return (0);
	else
		return (1);
}

void	remove_line_in_stash(char *stash, int size_line)
{
	int	i;

	i = 0;
	while (stash[size_line + i])
	{
		stash[i] = stash[size_line + i + 1];
		i++;
	}
	while (stash[i])
	{
		stash[i] = 0;
		i++;
	}
}

char	*get_line(char *stash)
{
	char	*line;
	int		size_line;
	int		i;

	size_line = 0;
	while (stash[size_line] != '\n' && stash[size_line] != '\0')
		size_line++;
	line = malloc((size_line + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	remove_line_in_stash(stash, size_line);
	return (line);
}

char	*get_result(char *stash, int size_read)
{
	char	*result;

	if (!stash)
		return (NULL);
	if (size_read == 0)
	{
		if (stash[0])
			result = get_line(stash);
		else
			return (NULL);
	}
	else
	{
		result = get_line(stash);
		// if (!ft_strchr_gnl(result, '\n'))
		// {
		// 	printf("debug\n");
		// 	free(stash);
		// }
	}
	if (!stash[0])
	{
		// printf("debug\n");
		free(stash);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			size_read;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	size_read = BUFFER_SIZE;
	while (!(is_end_of_line(stash, size_read)))
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (size_read == 0)
			break ;
		stash = ft_strjoin_gnl(stash, buffer, size_read);
	}
	free(buffer);
	return (get_result(stash, size_read));
}
