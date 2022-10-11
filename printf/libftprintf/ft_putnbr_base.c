/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:18:36 by jghribi           #+#    #+#             */
/*   Updated: 2022/09/04 11:59:37 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_base(int nbr, char x)
{
	int		j;
	char	i;
	char *base;
	char *base1;
	base1 = 
	base = "123456789abcdef"
	
	long	n;

	n = (long) nbr;
	j = strlen("")
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (is_base_valide(base) == 1)
		return ;
	if (n >= j)
	{
		ft_putnbr_base(n / j, base);
	}
	i = base[n % j];
	ft_putchar(i);
}
