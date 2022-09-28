#include "libft.h"

char *ft_strchr(char *str, int c)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return str;
		i++;
	}
	return str;
}

int main(int argc, char **argv)
{
	(void) argc;
	printf("%s\n", strchr(argv[1], argv[2][0])); 
	printf("%s\n", ft_strchr(argv[1], argv[2][0])); 
}
