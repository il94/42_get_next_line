#include <stdio.h>
#include <stdlib.h>
#include "../Get_next_line/get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;
	int		y;

	i = 1;
	y = 0;
	line = NULL;
	if (ac == 1)
	{
		printf("Please enter some files ...\n");
		return (0);
	}
	while (i < ac)
	{
		printf("\nTest fichier %d : %s\n", i, av[i]);
		fd = open(av[i], O_RDONLY);
		y = 0;
		while (y < 5)
		{
			line = get_next_line(fd);
			printf("%s", line);
			if (line)
			{
				free(line);
				line = NULL;
			}
			y++;
		}
		close(fd);
		i++;
	}
	return (0);
}
