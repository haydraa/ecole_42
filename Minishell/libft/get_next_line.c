/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:01:46 by cormiere          #+#    #+#             */
/*   Updated: 2023/01/10 16:44:54 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	some_error(char *str)
{
	if (str)
		free(str);
	return (-1);
}

int	gnl_static(char *rem, char *buf, char **line, int fd)
{
	int	rd;

	rd = 1;
	while (!find_nl(rem) && rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			return (some_error(buf));
		buf[rd] = '\0';
		rem = ft_strjoin(rem, buf);
	}
	free(buf);
	*line = get_line(rem);
	rem = trim_rem(rem);
	if (buf && fd == 0)
		free (rem);
	if (rd == 0 && !rem)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*rem;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (some_error(rem));
	gnl_static(rem, buf, line, fd);
	return (1);
}
