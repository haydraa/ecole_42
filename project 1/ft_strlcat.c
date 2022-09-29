#include "libft.h"

#include <bsd/string.h>

unsigned int ft_strlcat(char *dest, char *src, int n)
{
	int i;
	int s;

	s = ft_strlen(src) + ft_strlen(dest);
	i = 0;
	while (n--)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return s;
}
int main()
{
	char dest[] = "";
	char src[] = "s";
	printf("%ld\n%s\n", strlcat(dest,src,3), dest);
	
	printf("%d\n%s\n", ft_strlcat(dest,src,3), dest);

}
