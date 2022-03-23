/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:55:51 by rtosun            #+#    #+#             */
/*   Updated: 2022/02/21 14:02:02 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	find_after(const char	*type, va_list arg, int *pos)
{
	int	counter;

	counter = 0;
	*pos += 1;
	if (type[*pos] == 'c')
		counter = ft_putchar(va_arg(arg, int));
	else if (type[*pos] == 's')
		counter = ft_coputstr(va_arg(arg, char *));
	else if (type[*pos] == 'p')
		counter = ft_printpadress(va_arg(arg, unsigned long long));
	else if (type[*pos] == 'd' || type[*pos] == 'i')
		counter = ft_putnbr(va_arg(arg, int));
	else if (type[*pos] == 'u')
		counter = ft_print_u_nbr(va_arg(arg, unsigned int));
	else if (type[*pos] == 'x')
		counter = ft_put_hex(va_arg(arg, int), 120);
	else if (type[*pos] == 'X')
		counter = ft_put_hex(va_arg(arg, int), 88);
	else if (type[*pos] == '%')
		counter = ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *type, ...)
{
	va_list	arg;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(arg, type);
	while (type[i])
	{
		if (type[i] != '%')
			counter += ft_putchar(type[i]);
		else
			counter += find_after(type, arg, &i);
		i++;
	}
	va_end(arg);
	return (counter);
}
