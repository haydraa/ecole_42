#include "philo.h"

long long get_time(void)
{
	struct timeval time;

	gettimeofday(&time ,NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long delta_time(long long time)
{
	if (time > 0)
		return (get_time() - time);
	return 0;
}

void	exec_action(long long time)
{
	usleep(time * 1000);
}
