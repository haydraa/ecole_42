#include "get_next_line.h"

char *get_next_line(int fd)
{
	int i, rd = 0;
	char car;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	char buffer == malloc(100000);
	while ((rd = read(fd, &car, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		buffer[i++] = car;
		if (car == '\n')
			break
	}
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}
