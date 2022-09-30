#include "libft.h"

char *ft_substr(char const *s, unsigned int star, size_t len)
{
	unsigned int i;
	int j;
	char *dest;
	int size;

	size = len - star;
	dest = (char*)malloc(sizeof(char) * (size + 1));
	i = star;
	j = 0;
	if (dest == NULL)
		return NULL;
	while (i < len && s[i] != '\0')
	{
		dest[j] = s[i];
		j++;
		i++;
	}	
	dest[i] = '\0';
	return dest;
}

