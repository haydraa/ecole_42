#include "philo.h"

//we need a loop that make the routine in finish
//and the algo of the routine 
//usleep welle be the controler of the timer 
// getting memofday is to prinf and control time //
// learn more about the protection of mutex

	
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
