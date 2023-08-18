#include "get_next_line.h"

char *get_next_line(int fd)
{
	int rd = 0;
	char car;
	int i = 0;
	char	*buffer;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(1000000);
	while ((rd = read(fd, &car, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		buffer[i] = car;
		if (car == '\n')
			break;
		i++;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}
/*		 #include <stdio.h>
  #include <fcntl.h>
  int main()
  {
      int fd = open("get_next_line.h", O_RDONLY);
      char *line;
      line = get_next_line(fd);
     printf("%s\\n\nn", line);
      free(line);
      line = get_next_line(fd);
      printf("%s\n", line);
      free(line);
      line = get_next_line(fd);
     printf("%s\n", line);
      free(line);
      line = get_next_line(fd);
      printf("%s\n", line);
      free(line);
  }
*/
