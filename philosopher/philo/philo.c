#include "philo.h"

//we need a loop that make the routine in finish
//and the algo of the routine 
//usleep welle be the controler of the timer 
// getting memofday is to prinf and control time //
// learn more about the protection of mutex

	
long long getting_time(void)
{
	long long millisecond; 
	struct timeval tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		write(2, "Error in ft_gettime\n", 21);
		return (-1);
	}

	millisecond = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
	return millisecond;
}

void	*thread(void *arg)
{
	t_data *data;
	int index;
	int left_fork;
	int right_fork;
	
	data = (t_data *)arg;
    index = *(int*)data->id;
	left_fork = index;
	right_fork = index + 1  % data->nop;
	while (1)
	{
        // think for a random amount of time
        printf("Philosopher %d is thinking.\n", index);
		sleep(rand() % 5);

         // take left fork
         pthread_mutex_lock(&data->forks[left_fork]);
        printf("Philosopher %d has taken fork %d.\n", index, left_fork);
 
        // take right fork
        pthread_mutex_lock(&data->forks[right_fork]);
        printf("Philosopher %d has taken fork %d.\n", index, right_fork);
 
       // eat for a random amount of time
         printf("Philosopher %d is eating.\n", index);
         sleep(rand() % 5);
 
          // release right fork
          pthread_mutex_unlock(&data->forks[right_fork]);
         printf("Philosopher %d has released fork %d.\n", index, right_fork);
  
          // release left for
		 pthread_mutex_unlock(&data->forks[left_fork]);
		printf("Philosopher %d has released fork %d.\n", index, left_fork);
 	}
}
