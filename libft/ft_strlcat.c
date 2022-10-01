/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:06:55 by jghribi           #+#    #+#             */
/*   Updated: 2022/09/30 17:06:59 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <bsd/string.h>

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	long int    i;
    long int    src_len;
    size_t        dst_len;
    size_t        new_size;

    i = 0;
    src_len = ft_strlen(src);
    if (size == 0)
        return (src_len);
    dst_len = ft_strlen(dest);
    if (dst_len > size)
        dst_len = size;
    new_size = (size_t)(size - dst_len);
    while (new_size > 1 && src[i])
    {
        dest[dst_len + i] = src[i];
        i++;
        new_size--;
    }
    if (i && !src[i])
        dest[dst_len + i] = '\0';
    return (src_len + dst_len);}

