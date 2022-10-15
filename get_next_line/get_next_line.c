#include "get_next_line.h"


char *ft_read(int fd)
{
	int i;
	static char *s;

	i = 0;
	while(read(fd,&s,1) == 0)
	{

		while(s[i] != "\n")
			i++;		
	}

}
char *get_next_line(int fd)
{

	static char *str;

	fd = open(fd, O_RDONLY);
	if (fd == -1)
		return -1;

}
