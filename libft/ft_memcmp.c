#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
    size_t i;	
   unsigned char *dest = (void*)str1;
	unsigned char *src = (void*)str2;

    i = 0;
    while (i < n)
    {
        	if (dest[i] != src[i])   
        		return (dest[i] - src[i]);
        	i++;
    }
    return (0);
}
