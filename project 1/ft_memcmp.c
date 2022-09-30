#include "libft.h"

void ft_memcmp(void *str1, void *str2, int n)
{
    int i;	
    char *dest = (char*) str1;
	char *src = (char*) str2;

    i = 0;
	 while (n--)
	 {
        dest[i] = src[i];
        i++;   
     }
    dest[i] = '\0';
}
