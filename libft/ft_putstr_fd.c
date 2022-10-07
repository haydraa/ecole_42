# include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
	int i;
	int j;

	if (s == NULL)
		return ;
	i = 0;
	j = ft_strlen(s);
	while(i <= j)
	{
		write(fd,&s[i],1);
		i++;
	}
}
