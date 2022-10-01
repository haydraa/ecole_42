#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t i)
{
	char *s = (char *) src;
	char *d = (char *) dest;
	
	size_t  j;

	j = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (j < i)
	{
		d[j] = s[j];
		j++;
	}
	return (dest);
}
