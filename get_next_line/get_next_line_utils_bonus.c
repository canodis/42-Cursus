#include "get_next_line_bonus.h"

int	ft_notnewline(char *s)
{
	int	ct;

	if (!s)
		return (1);
	ct = -1;
	while (s[++ct])
	{
		if (s[ct] == '\n')
			return (0);
	}
	return (1);
}

int	ft_linelen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && s[i])
			return (i + 1);
		i++;
	}
	return (i);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(char *save, int len)
{
	char	*s1;
	int		i;

	if (!*save)
		return (NULL);
	s1 = malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	i = -1;
	while (++i < len)
		s1[i] = save[i];
	s1[i] = 0;
	return (s1);
}

char	*save_rest(char *save, int len)
{
	char	*s2;
	int		len_2;
	int		j;

	if (!*save)
	{
		free(save);
		return (NULL);
	}
	len_2 = ft_strlen(&save[len]);
	s2 = malloc(sizeof(char) * (len_2 + 1));
	if (!s2)
		return (NULL);
	j = 0;
	while (save[len])
		s2[j++] = save[len++];
	s2[j] = 0;
	free(save);
	return (s2);
}
