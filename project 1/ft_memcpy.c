#include "libft.h"

void *ft_memcpy(void *dest, void *src, int i)
{
	char *s = (char *) src;
	char *d = (char *) dest;
	
	int j;

	j = 0;
	while (j < i)
	{
		d[j] = s[j];
		j++;
	}
	return (dest);
}

#include <string.h>

int main()
{
	char s[] = "jaleleddine";
	char d[12];
	memcpy(d, s, 11);
	printf("%s\n", d);
	printf("%s\n", ft_memcpy(d,s,11));
}
