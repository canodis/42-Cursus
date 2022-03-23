/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:39:21 by rtosun            #+#    #+#             */
/*   Updated: 2022/02/22 13:39:25 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int main()
{
	char	*ptr = "can";
	int		a = 3;
	unsigned int	b = -3;
	int 	ps;
	ft_printf("\n\n\nft_printf : \n");
	ps = ft_printf("char : %c\nstring : %s\npointer : %p\ndecimal : %d\ninteger : %i\nunsigned : %u\nhex(x) : %x\nhex(X) : %X\nyuzde : %%\n", *ptr, ptr, ptr, a, a, b, a, b);
	ft_printf("uzunluk : %i\n",ps);
	ft_printf("\nprintf : \n");
	ps = printf("char : %c\nstring : %s\npointer : %p\ndecimal : %d\ninteger : %i\nunsigned : %u\nhex(x) : %x\nhex(X) : %X\nyuzde : %%\n", *ptr, ptr, ptr, a, a, b, a, b);
	printf("uzunluk : %i\n\n\n",ps);
}
