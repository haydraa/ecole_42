/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:23:39 by jghribi           #+#    #+#             */
/*   Updated: 2022/08/21 17:39:51 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void ecrire(char c)
{
	write(1, &c, 1);
}

void ft_print_comb2(void)
{ 
	int a;
	int b;

	a = 0;

	while (a<=98)
	{
		b= a+1;
		while (b<=99)
 		{
			ecrire(a);
		}
	a++; 
	}
}
int main(void)
{
	ft_print_comb2();
}
