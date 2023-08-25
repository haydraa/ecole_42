#include "get_next_line.h"

char *get_next_line(int fd)
{
	int rd = 0;
	int i = 0;
	char c;
	char *buffer;

	if (BUFFER_SIZE <= 0)
		return NULL;
	buffer = malloc(100000);
	while ((rd = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1)) > 1)
	{
		buffer[i++] = c;
		if (c == '\n')
			break;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer || !rd))
		return (free(buffer), NULL);
	return (buffer);
}
