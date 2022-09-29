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
    char *dest;
    j = ft_strlen(convert);
    i = 0;
    dest = malloc(sizeof(char) * j + 1);
    while (i <= j )
    {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return dest;
}
int main()
{
    const char d[] = "hello mark";
    char *dest;
    dest = ft_strdup(d);
    printf("%s\n", dest);
    free(dest);
}