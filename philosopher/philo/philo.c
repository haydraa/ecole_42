#include "philo.h"

long long getting_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		write(2, "Error in ft_gettime\n", 21);
		return (-1);
	}
	return 	((tv.tv_sec * 1000) + (tv.tv_usec * 0.001));
}

void	*thread(void *arg)
{
	t_data *data;
//	int index;
	long long i;
	data = (t_data *)arg;
	
	while (1)
	{
		i = getting_time();
		printf("%lld\n", i);
 	}
}
