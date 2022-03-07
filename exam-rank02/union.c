#include <unistd.h>

int checkDoubles(char *dizi, char c, int pos)
{
	int i = 0;
	while (i < pos)
	{
		if (dizi[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (checkDoubles(argv[1], argv[1][i], i) == 1)
				write (1, &argv[1][i], 1);
			i++;
		}
		int j = 0;
		while (argv[2][j])
		{
			if (checkDoubles(argv[1], argv[2][j], i) == 1)
				if (checkDoubles(argv[2], argv[2][j],j) == 1)
					write (1, &argv[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
}