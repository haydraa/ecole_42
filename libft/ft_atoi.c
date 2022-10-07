#include "libft.h"

int white_space(const char nptr)
{
	if ((nptr > 8 && nptr < 14) || nptr == ' ')
		return (0);
	return (1);
}
int ft_atoi(const char *nptr)
{
	int i;
	int s;
	long int result;

	i = 0;
	s = 1;
	result = 0;
	while ((white_space(nptr[i]) == 0 ))
			i++;
	while (nptr[i] == '-' || nptr[i] == '+')
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
