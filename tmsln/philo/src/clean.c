#include "../inc/philo.h"

int	clean_mem(t_rules *r)
{
	int	i;

	i = 0;
	while (i < r->nb_philo)
	{
		if (!&(r->forks[i]))
			pthread_mutex_destroy(&(r->forks[i]));
		i++;
	}
	if (&(r->printing.__data))
		pthread_mutex_destroy(&(r->printing));
	if (&(r->health_check.__data))
		pthread_mutex_destroy(&(r->health_check));
	if (r)
		free(r);
	return (0);
}
