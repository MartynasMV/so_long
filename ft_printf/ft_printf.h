/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoldema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:21:46 by mvoldema          #+#    #+#             */
/*   Updated: 2022/11/14 14:21:49 by mvoldema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <ctype.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	c_putstr(char *s, int counter);
int	c_putchar(char c, int counter);
int	c_putnbr(int n, int counter);
int	uns_c_putnbr(unsigned int n, int counter);
int	hex_count(unsigned int n);
int	to_hexi_x_big(unsigned int num, int counter);
int	to_hexi_x_small(unsigned int num, int counter);
int	pointer(unsigned long pointer, int counter);
int	to_hexi_pointer(unsigned long num, int counter);

#endif
