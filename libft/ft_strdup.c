/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:21:03 by marvin            #+#    #+#             */
/*   Updated: 2022/09/29 23:21:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *src)
{
    char *convert;
    convert = (char*)src;
    int i;
    int j;
    int x;
    char *dest;
    j = ft_strlen(convert);
    i = 0;
    x = 0;
    dest = malloc(sizeof(char) * j + 1);
    if (dest == NULL)
	    return NULL;
    while (i < j)
    {
        dest[x] = convert[i];
        i++;
        x++;
    }
    dest[j] = '\0';
    return dest;
}

