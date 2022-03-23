/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 00:01:28 by rtosun            #+#    #+#             */
/*   Updated: 2022/02/20 00:21:58 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_putchar(char c);
int		ft_printpadress(unsigned long long adress);
int		ft_putnbr(int n);
int		ft_print_u_nbr(unsigned int nb);
int		ft_put_hex(unsigned int nbr, int a);
int		ft_coputstr(char *str);
int		ft_strlen(char	*str);
int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);

#endif
