/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:45:36 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/22 18:39:28 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		i = 0;
	int		j = 0;
	int		k = 0;
	int		number_of_lines = 12;
	char	*str;

	fd = open("./file/file", O_RDONLY);
	fd2 = open("./file/file2", O_RDONLY);
	fd3 = open("./file/file3", O_RDONLY);
	if (fd >= 0)
	{
		while (i < number_of_lines)
		{
			str = get_next_line(fd);
			printf("FD 1 RESULT Line %d = %s", i++, str);
			if (i < number_of_lines)
				free(str);
			str = get_next_line(fd2);
			printf("FD 2 RESULT Line %d = %s", j++, str);
			if (i < number_of_lines)
				free(str);
			str = get_next_line(fd3);
			printf("FD 3 RESULT Line %d = %s", k++, str);
			if (i < number_of_lines)
				free(str);
		}
		close(fd);
	}
	return (0);
}
