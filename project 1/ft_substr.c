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
	
int main()
{
    char src[] = "substr function Implementation";
 
    int m = 2;
    int n = 1;
 
    char* dest = ft_substr(src, m, n);
 
    printf("%s\n", dest);
    free(dest);
 
    return 0;
}

