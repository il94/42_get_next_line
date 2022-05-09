
int	main(void)
{
	int		fd;
	int		i = 1;
	char	*str;

	fd = open("./file", O_RDONLY);
	if (fd > 0)
	{
		while (i - 1 < 11)
		{
			str = get_next_line(fd);
			printf("Line %d = %s", i++, str);
			free(str);
		}
		close(fd);
	}
	return (0);
}
