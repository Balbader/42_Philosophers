#include <pthread.h>
#include <stdio.h>
#include "boolean.h"
#include "philosophers.h"
#include "philo_diner.h"

t_bool	announce_death(t_philo *philo, time_t time, char *msg)
{
	time -= philo->start_time;
	pthread_mutex_lock(philo->is_speaking);
	if (!*philo->is_diner_over)
	{
		printf("%10lums  %d  %s\n", time, philo->id, msg);
		*philo->is_diner_over = TRUE;
	}
	pthread_mutex_unlock(philo->is_speaking);
	return (FALSE);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}

t_bool	speak(t_philo *philo, time_t time, char *msg)
{
	if (ft_strcmp(MIN_NB_MEAL, msg)
		&& (time - philo->last_meal) > philo->time_to_die)
		return (FALSE);
	time -= philo->start_time;
	pthread_mutex_lock(philo->is_speaking);
	if (!ft_strcmp(MIN_NB_MEAL, msg) && !*philo->is_diner_over)
	{
		*philo->is_diner_over = TRUE;
		printf("%s %d %.*s\n", msg,
			philo->min_nb_meal, 5 - (philo->min_nb_meal <= 1), "times");
	}
	else if (!ft_strcmp(EAT, msg) && !*philo->is_diner_over)
		printf("%10lums  %d  %s\n%10lums  %d  %s\n", time, philo->id, FORK,
			time, philo->id, msg);
	else if (!*philo->is_diner_over)
		printf("%10lums  %d  %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->is_speaking);
	return (!*philo->is_diner_over);
}
