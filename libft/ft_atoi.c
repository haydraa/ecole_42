#include "libft.h"

int ft_atoi(const char *nptr)
{
	int i;
	int s;
	int result;

	i = 0;
	s = 1;
	result = 0;
	while ((ft_isprint(nptr[i]) == 0 ) || (nptr[i] == ' '))
			i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) == 1)
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * s);
}
