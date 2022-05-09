/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:01:42 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/09 12:00:42 by ilandols         ###   ########.fr       */
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
			if (str[i] == '\n' || str[i] == EOF)
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
	while (stock[size_line + i + 1])
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

char	*get_line(char *stock)
{
	char	*line;
	int		size_line;
	int		i;

	size_line = 0;
	while (stock[size_line] != '\n' && stock[size_line] != EOF && stock[size_line] != '\0')
		size_line++;
	line = malloc((size_line + 2) * sizeof(char));
	i = 0;
	while (stock[i] != '\n' && stock[i] != EOF && stock[i] != '\0')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = stock[i];
	line[i + 1] = '\0';
	remove_line_in_stock(stock, size_line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		buffer[BUFFER_SIZE];
	char		*result;
	int			size_read;

	size_read = BUFFER_SIZE;
	while (!(check_end_of_line(stock, size_read)))
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read <= 0)
			break ;
		stock = ft_strjoin(stock, buffer);
	}
	result = get_line(stock);
	return (result);
}
