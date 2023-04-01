#include "philo.h"
	
long long getting_time(void)
{
	long long millisecond; 
	t_timeval tv;
	if (gettimeofday(&tv, NULL) != 0)
	{
		write(2, "Error in ft_gettime\n", 21);
		return (-1);
	}

	millisecond = (tv.tv_sec) * 1000 + (tv.tv_used) / 1000 ;
	return millisecond;
}

void	phil
