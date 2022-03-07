#include "get_next_line.h"

char *get_next_fkng_line(int fd)
{
	char *dizi = malloc(9999);
	int rd_bytes = 1;
	int i = 0;
	char buff;

	if (fd < 0) /*|| BUFFER_SIZE < 0*/
		return (0);
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, &buff, 1);
		if (rd_bytes <= 0)
			break;
		dizi[i++] = buff;
		if (buff == '\n')
			break;
	}
	dizi[i] = 0;
	if (!*dizi)
	{
		free(dizi);
		return (NULL);
	}
	return (dizi);
}
/*
int	main(void)
{
	int		fd = open("erased", O_RDONLY);
	char	*line;

	line = NULL;
	while ((line = get_next_fkng_line(fd)))
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
}*/