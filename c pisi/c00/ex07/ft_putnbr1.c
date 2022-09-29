/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:28:17 by jghribi           #+#    #+#             */
/*   Updated: 2022/09/02 10:37:51 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putnbr(int nb)
{
	int i;	
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}	
	i = (nb % 10) + 48;
	ft_putchar (i);
}
int main()
{
	ft_putnbr(78954
);
}
