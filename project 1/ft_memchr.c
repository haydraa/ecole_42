/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:48:44 by marvin            #+#    #+#             */
/*   Updated: 2022/09/28 19:48:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "libft.h"

void *ft_memchr(const void *str, int c, unsigned int n)
{
	unsigned char *s = (unsigned char*) str;
	unsigned char *found = NULL;

	while ((str != NULL) && (n--))
	{
		if (*s != (unsigned char)c)
			s++;
		else 
		{
			found = s;
			break ;
		}
	}
	return found;
}

int main()
{
    char s[] = "Aticleworld";

    //called own created memchr function
    char *ptr = ft_memchr(s,'c',sizeof(s));
    if (ptr != NULL)
    {
        printf ("'c' found at position %ld.\n", ptr-s+1);
        printf ("search character found:  %s\n", ptr);
    }
    else
    {
        printf ("search character not found\n");
    }
    return 0;
}
