#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	FILE	*fp;
	char	*line;
	size_t	n;
	ssize_t	rd;
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
		fp = fopen(av[i], "r");
		y = 0;
		while (y < 5)
		{
			rd = getline(&line, &n, fp);
			if (rd == -1)
				printf("(null)");
			else
				printf("%s", line);
			if (line)
			{
				free(line);
				line = NULL;
			}
			y++;
		}
		fclose(fp);
		i++;
	}
	return (0);
}
		
