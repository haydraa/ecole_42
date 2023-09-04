#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return (i);
}

char *get_next_line(int fd)
{
	int rd;
	char *buffer;

	buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	while ((rd = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		printf("%s", buffer);
	}
	return (buffer);
}

int main()
{
	int fd = open("get_next_line.h", O_RDONLY);
	char *line = get_next_line(fd);
}
