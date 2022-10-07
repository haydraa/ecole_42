# include"libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int i;
	char *dest;
	int len;

	if (s == NULL || f == NULL )
		return NULL;
	i = 0;
	len = ft_strlen(s);
	dest = malloc(sizeof(char)* len + 1);
	if (dest == NULL)
		return NULL;
	ft_strlcpy(dest,s,len + 1);
	while (dest[i])
	{
		dest[i] = f(i,dest[i]);
		i++;
	}
	return (dest);
}

