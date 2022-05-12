/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:45:36 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/11 11:47:21 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i = 1;
	char	*str;
	char	*buffer[BUFFER_SIZE];

	fd = open("./file", O_RDONLY);
	if (fd > 0)
	{
		while (i - 1 < 11)
		{
			// str = get_next_line(fd);
			printf("%ld\n", read(fd, buffer, BUFFER_SIZE));
			printf("RESULT Line %d = %s", i, str);
			i++;
			free(str);
		}
		close(fd);
	}
	return (0);
}
