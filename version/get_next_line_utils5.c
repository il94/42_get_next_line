/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:16:48 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/20 10:48:47 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *stash, char const *buffer, int size_read)
{
	char	*result;
	int		size_stash;
	int		i;
	int		j;

	size_stash = ft_strlen_gnl(stash);
	result = malloc((size_stash + size_read + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < size_stash)
		result[i] = stash[i];
	while (i < size_stash + size_read)
		result[i++] = buffer[j++];
	result[i] = '\0';
	// if (stash)
		free(stash);
	return (result);
}

int	ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
