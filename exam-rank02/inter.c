#include <stdio.h>

int checkd(char *dizi, char c, int pos)
{
	int i = 0;
	while(i < pos)
	{
		if (dizi[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int checkd2(char *dizi, char c)
{
	int i = 0;
	while (dizi[i])
	{
		if (dizi[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if(checkd(argv[1], argv[1][i], i) == 1)
			{
				if (checkd2(argv[2],argv[1][i]))
					printf("%c",argv[1][i]);
			}
			i++;
		}
	}
	printf("\n");
}