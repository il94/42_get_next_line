/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:01:42 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/15 06:55:10 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_end_of_line(char *str, int size_read)
{
	int	i;

	i = 0;
	if (str == NULL || size_read != BUFFER_SIZE)
		return (0);
	if (size_read == BUFFER_SIZE)
	{
		while (str[i]) 
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

void	remove_line_in_stock(char *stock, int size_line)
{
	int	i;

	i = 0;
	while (stock[size_line + i])
	{
		stock[i] = stock[size_line + i + 1];
		i++;
	}
	while (stock[i])
	{
		stock[i] = 0;
		i++;
	}
}

char	*get_line(char *stock, int *last)
{
	char	*line;
	int		size_line;
	int		i;

	size_line = 0;
	while (stock[size_line] != '\n' && stock[size_line] != '\0')
		size_line++;
	// if (stock[size_line] != '\n')
	// 		size_line++;
	line = malloc((size_line + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		*last = 1;
		line[i] = '\n';
		i++;
	}
	else
		*last = 0;
	line[i] = '\0';
	remove_line_in_stock(stock, size_line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buffer;
	char		*result;
	int			size_read;
	int			last;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	size_read = BUFFER_SIZE;
	while (!(check_end_of_line(stock, size_read)))
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (size_read == 0)
			break ;
		stock = ft_strjoin(stock, buffer, size_read);
	}
	free(buffer);
	if (!stock)
		return (NULL);
	last = 0;
	if (size_read == 0)
	{
		// printf("IF 1\n");
		if (stock[0])
		{
			// printf("IF 2\n");
			result = get_line(stock, &last);
						// printf("last = %d\n", last);

			// printf("stock = %s\n", stock);
			if (stock[0])
			{
				// printf("IF 2.5\n");				
				free(stock);
			}
		}
		else
		{
			// printf("ELSE 2\n");
			// free(stock);
						// printf("last = %d\n", last);

			return (NULL);
		}
		
	}
	else
	{
		// printf("ELSE 1\n");
		result = get_line(stock, &last);
		if (stock && last == 0)
		{
			// printf("IF 1.5\n");				
			free(stock);
		}
	}
	return (result);
}

		// printf("stock = %s\n\n", stock);
		// printf("buffer = %s\n\n", buffer);
		// printf("size_read = %d\n\n", size_read);


	// printf("stock = %s\n\n", stock);
	// else
	// {
	// 	// printf("ELSE\n");
	// 	result = malloc(2 * sizeof(char));
	// 	result[0] = '\n';
	// 	result[1] = '\0';
	// 	free(stock);

	// }

	// if (stock[0] == '\0' && size_read == 0)
	// 	free(stock);





















	