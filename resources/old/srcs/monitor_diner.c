#include <pthread.h>
#include "boolean.h"
#include "philo_utils.h"
#include "philosophers.h"
#include "philo_diner.h"

void	*monitor_philo(void *arg)
{
	t_philo		*philo;
	time_t		time;

	philo = (t_philo *)arg;
	while (!*philo->is_diner_over)
	{
		pthread_mutex_lock(philo->is_eating);
		time = get_time();
		if (!*philo->is_diner_over
			&& (time - philo->last_meal) > philo->time_to_die)
		{
			if (philo->min_nb_meal >= 0 && philo->nb_meal == philo->min_nb_meal)
				ft_usleep(1000);
			if (!*philo->is_diner_over)
				announce_death(philo, time, DIE);
		}
		pthread_mutex_unlock(philo->is_eating);
		if (!*philo->is_diner_over)
			ft_usleep(1000);
	}
	return (arg);
}

void	monitor_nb_meals(t_philo *philosophers, int nb_philo, int min_nb_meal)
{
	int			i;
	t_philo		*philo;

	while (!*philosophers[0].is_diner_over)
	{
		i = 0;
		while (i < nb_philo)
		{
			philo = &philosophers[i];
			if (philo->nb_meal < min_nb_meal)
				break ;
			if ((i + 1) == nb_philo)
			{
				speak(philo, get_time(), MIN_NB_MEAL);
				*philo->is_diner_over = TRUE;
				return ;
			}
			i++;
		}
		ft_usleep(1000);
	}
}
