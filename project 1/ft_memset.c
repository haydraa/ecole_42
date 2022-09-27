/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:50:26 by marvin            #+#    #+#             */
/*   Updated: 2022/09/26 21:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
# include <stdio.h>
# include "libft.h"
void ft_memset(void *str, unsigned int value, int size)
{
	char	        *m = (char*) str;
	int i;
	i = 0;
	while (i < size)
	{
		m[i] = value;
		i++;
	}
}
int main()
{
	char *str[10] = "hsidh kjd";
	printf("%p" ,memset(str, 8 , 4));
//	printf("%p" ,ft_memset(str, 8, 4));
}
