#include <stdio.h>
#include <stdlib.h>

FILE	**initialise_tab(int ac, char **av)
{
	int		i;
	FILE 	**fps;

	i = 1;
	fps = malloc((ac - 1) * sizeof(FILE *));
	if (!fps)
		return (NULL);
	while (i < ac)
	{
		fps[i - 1] = fopen(av[i], "r");
		i++;
	}
	return (fps);
}

void	close_file(FILE **fps, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		fclose(fps[i]);
		i++;
	}
	free(fps);
}	

int	main(int ac, char **av)
{
	FILE	**fps;
	char	*line;
	size_t	n;
	ssize_t	rd;
	int		i;
	int		y;

	y = 0;
	line = NULL;
	rd = -1;
	if (ac == 1)
	{
		printf("Please enter some files ...\n");
		return (0);
	}
	fps = initialise_tab(ac, av);
	while (y < 6)
	{
		i = 1;
		while (i < ac)
		{
			printf("\nTest fichier %d : %s\n", i, av[i]);
			rd = getline(&line, &n, fps[i - 1]);
			if (rd == -1)
				printf("(null)");
			else
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
	close_file(fps, ac);
	return (0);
}
