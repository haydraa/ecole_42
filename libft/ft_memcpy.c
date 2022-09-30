#include "libft.h"

void *ft_memcpy(void *dest, void *src, int i)
{
	char *s = (char *) src;
	char *d = (char *) dest;
	
	int j;

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
