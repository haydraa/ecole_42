#include <stdio.h>
#include <string.h>

char *revstr(char *str)
{
	int	i = 0;
	int	len = strlen(str);
	char tmp;

	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
	return (str);
}

int	main(void)
{
		
}
