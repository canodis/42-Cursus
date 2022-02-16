/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 06:06:54 by rtosun            #+#    #+#             */
/*   Updated: 2022/02/16 16:22:51 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*veriyi_birlestir(char *save, char *s2, int i, int j)
{
	char	*str;

	if (!save)
	{
		str = malloc(sizeof(char) * ft_strlen(s2) + 1);
		if (!str)
			return (NULL);
		while (s2[++i])
			str[i] = s2[i];
	}
	else
	{
		str = malloc(sizeof(char) * (ft_strlen(save) + ft_strlen(s2)) + 1);
		if (!str || !save || !s2)
			return (NULL);
		while (save[++i])
			str[i] = save[i];
		while (s2[++j])
			str[i++] = s2[j];
	}
	str[i] = 0;
	free(save);
	return (str);
}

char	*veriyi_oku(int fd, char *save)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	i = 1;
	while (ft_notnewline(save) && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1 || (!save && i == 0))
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		save = veriyi_birlestir(save, str, -1, -1);
		if (!save)
			return (NULL);
	}
	free (str);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = veriyi_oku(fd, save);
	if (!save)
		return (NULL);
	len = ft_linelen(save);
	line = ft_strndup(save, len);
	save = save_rest(save, len);
	return (line);
}
