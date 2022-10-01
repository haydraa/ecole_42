#include "libft.h"

void *ft_calloc(size_t nemb, size_t size)
{
	size_t i;
	char *dest;

	i = 0;

	if (nemb == 0 || size <= 0)
		return (NULL);
	dest =malloc(sizeof(size) * nemb + 1);
	if (dest == NULL)
		return (NULL);

	while (i < nemb + 1)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
