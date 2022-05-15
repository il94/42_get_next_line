/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:16:48 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/15 04:27:28 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *stock, char const *buffer, int size_buffer)
{
	char	*result;
	int		size_stock;
	int		i;
	int		j;

	if (stock == NULL)
	{
		size_stock = 0;
	}
	else
		size_stock = strlen(stock);
	// printf("size_stock = %d\n", size_stock);
	// printf("size_read = %d\n\n", size_buffer);
	if (size_buffer > 0 || size_stock > 0)
	{
		result = malloc((size_stock + size_buffer + 1) * sizeof(char));
		if (!result)
			return (NULL);
	}
	else
	{
		// printf("STRJOIN \n");
		free(stock);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (i < size_stock)
	{
		result[i] = stock[i];
		i++;
	}
	while (i < size_stock + size_buffer)
	{
		result[i] = buffer[j];
		i++;
		j++;
	}
	result[i] = '\0';
	free(stock);
	return (result);
}

static size_t	get_size(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return ((char *)&s[get_size(s)]);
	else if (c > 256)
		c -= 256;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
