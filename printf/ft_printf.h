/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:53:04 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/12 13:08:25 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_strlen(const char *str);
int	ft_print_base(unsigned int nbr, const char *base);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr1(unsigned int n);
int	ft_putnbr(int nb);
int	ft_pointeur(unsigned long long p);

# endif
