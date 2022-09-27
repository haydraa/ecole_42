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

# include "libft.h"
#include <string.h>

void *ft_memset(void *str, int value, unsigned int size)
{
	unsigned char* p = str;

	while (size--)
	{
		*p++ = (unsigned char) value;
	}
	return (str);
}

int main()
{
	char str[20] =  "hsidhkjd";
	memset(str + 5,'x', 4);
	printf("%s\n", str);
	ft_memset(str + 5,'0',4 );
	printf("%s\n", str);
}
