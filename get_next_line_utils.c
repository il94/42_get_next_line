/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:16:48 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/11 11:45:28 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2, int size2)
{
	char	*result;
	int		size1;
	int		i;
	int		j;

	if (s1 == NULL)
		size1 = 0;
	else
		size1 = strlen(s1);
	if (size2 > 0 || size1 >= 0)
		result = malloc((size1 + size2 + 1) * sizeof(char));
	else
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (i < size1)
	{
		result[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	if (s1)
		free(s1);
	return (result);
}
