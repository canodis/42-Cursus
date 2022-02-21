/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:52:30 by rtosun            #+#    #+#             */
/*   Updated: 2022/02/20 00:13:59 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_put_u_nbr(unsigned int nb)
{
	if (nb > 9)
	{
		ft_put_u_nbr(nb / 10);
		ft_put_u_nbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int	ft_print_u_nbr(unsigned int n)
{
	int		length;
	char	*str;

	length = 0;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		str = ft_uitoa(n);
		length += ft_coputstr(str);
		free(str);
	}
	return (length);
}
