/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 06:31:57 by rtosun            #+#    #+#             */
/*   Updated: 2022/02/16 16:23:03 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_notnewline(char *s)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (*s == '\n')
			return (0);
		s++;
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
