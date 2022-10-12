/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointeur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:56:30 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/12 20:01:02 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void pointeur(unsigned long long p, int *len)
{
	char *base;
	unsigned long j;
	char i;

	base = "0123456789abcdef";
	j = ft_strlen(base);
	if (p >= j)
	{
		pointeur(p / j,len);
	}
	i = base[p % j];
	*len += ft_putchar(i);
}
int ft_pointeur(unsigned long long p)
{
	int len;
	len = 2;
	if (p == 0)
	{
		ft_putstr("(nil)");
		return 5;
	}
	ft_putchar('0');
	ft_putchar('x');
	pointeur(p, &len);
	return len;
}

/*int main()
{
	int i;

	int k;
	k = 7;

	i = &k;

	printf("%p\n" , -1);
	ft_pointeur( -1); 
}*/

