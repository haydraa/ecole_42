#include "get_next_line.c"

char *get_next_line(int fd)
{
	int i = 0;
	int rd = 0;
	char car;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	char *buffer = malloc(1000000);
	while ((rd = read(fd, &car, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		buffer[i++] = car;
		if (car == '\n')
			break;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}
