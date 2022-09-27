# include "libft.h"

int ft_strlcpy(char *dest, char *src, int size)
{
	int i;
	int j;	
	i = 0;

	j = ft_strlen(src);
	while (i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}

