/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:16:48 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/05 17:16:58 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		size1;
	int		size2;
	int		i;
	int		j;

	size1 = strlen(s1);
	size2 = strlen(s2);
	result = malloc((size1 + size2 + 1) * sizeof(char));
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
	return (result);
}
