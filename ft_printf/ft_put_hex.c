/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:55:43 by rtosun            #+#    #+#             */
/*   Updated: 2022/02/20 00:02:41 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put(unsigned int num, int a)
{
	if (num >= 16)
	{
		ft_put(num / 16, a);
		ft_put(num % 16, a);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (a == 'x')
				ft_putchar((num - 10 + 'a'));
			else if (a == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

int	ft_put_hex(unsigned int num, int a)
{
	if (num == 0)
		return (ft_putchar('0'));
	ft_put(num, a);
	return (ft_hex_len(num));
}
