#include "libft.h"

void *ft_bzero(void *s, unsigned int i)
{
	unsigned char* p = s;

	while (i--)
	{
		*p++ = '\0';
	}
	return (s);
}
