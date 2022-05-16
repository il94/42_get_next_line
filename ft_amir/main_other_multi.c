#include <stdio.h>
#include <stdlib.h>
#include "../Get_next_line/get_next_line.h"
#include <fcntl.h>

void	initialise_tab(int **fds, int ac, char **av)
{
	int	i;

	i = 1;
	*fds = malloc(ac * sizeof(int));
	if (!*fds)
		return ;
	while (i < ac)
	{
		(*fds)[i - 1] = open(av[i], O_RDONLY);
		i++;
	}
}

void	close_file(int *fds, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		close(fds[i]);
		i++;
	}
	free(fds);
}	

int	main(int ac, char **av)
{
	int		*fds;
	char	*line;
	int		i;
	int		y;

	y = 0;
	line = NULL;
	if (ac == 1)
	{
		printf("Please enter some files ...\n");
		return (0);
	}
	initialise_tab(&fds, ac, av);
	while (y < 6)
	{
		i = 1;
		printf("\nTest fichier %d : %s\n", i, av[i]);
		while (i < ac)
		{
			line = get_next_line(fds[i - 1]);
			printf("%s", line);
			if (line)
			{
				free(line);
				line = NULL;
			}
			i++;
		}
		y++;
	}
	close_file(fds, ac);
	return (0);
}
