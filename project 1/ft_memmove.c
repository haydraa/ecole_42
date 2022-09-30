#include "libft.h"

void *ft_memmove(void *dest, void *src, int n)
{
        char *str1;
        char *str2;
        char temp[ft_strlen(src)];
        int i;
        
        i = 0;
        str1 = (char *)dest;
        str2 = (char *)src;
		if (str2 == NULL)
			return NULL;
        while (i < n)
        {
		temp[i] = str2[i];
		i++;
        }
	i = 0;
	while (i < n)
	{
		str1[i] = temp[i];
		i++;
	}
	str1[i] = '\0';
	return str1;
}
