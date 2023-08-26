#include <stdlib.h>
#include "boolean.h"
#include "philo_utils.h"
#include "philo_parsing.h"
#include "philosophers.h"

#define MUTEX_INIT		"A mutex couldn't be initialized"
#define MUTEX_ALLOC		"A mutex array couldn't be allocated"
#define PHILO_ALLOC		"The philosophers couldn't be allocated"

static t_bool	init_array_mutexes(pthread_mutex_t *forks,
									pthread_mutex_t *is_eating, int nb_philo)
{
	int		i;
	int		forks_error;
	int		is_eating_error;

	i = 0;
	while (i < nb_philo)
	{
		forks_error = pthread_mutex_init(&forks[i], NULL);
		is_eating_error = pthread_mutex_init(&is_eating[i], NULL);
		if (forks_error || is_eating_error)
		{
			if (!forks_error)
				pthread_mutex_destroy(&forks[i]);
			if (!is_eating_error)
				pthread_mutex_destroy(&is_eating[i]);
			while (--i >= 0)
			{
				pthread_mutex_destroy(&forks[i]);
				pthread_mutex_destroy(&is_eating[i]);
			}
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_bool	init_mutexes(t_mutexes *mutexes, int nb_philo)
{
	if (pthread_mutex_init(&mutexes->is_speaking, NULL) != 0)
		return (print_error(MUTEX_INIT, NULL, FALSE));
	mutexes->forks = malloc(nb_philo * sizeof(pthread_mutex_t));
	mutexes->is_eating = malloc(nb_philo * sizeof(pthread_mutex_t));
	if (!mutexes->forks || !mutexes->is_eating)
	{
		pthread_mutex_destroy(&mutexes->is_speaking);
		if (mutexes->forks)
			free(mutexes->forks);
		if (mutexes->is_eating)
			free(mutexes->is_eating);
		return (print_error(MUTEX_ALLOC, NULL, FALSE));
	}
	if (!init_array_mutexes(mutexes->forks, mutexes->is_eating, nb_philo))
	{
		pthread_mutex_destroy(&mutexes->is_speaking);
		free(mutexes->forks);
		free(mutexes->is_eating);
		return (print_error(MUTEX_INIT, NULL, FALSE));
	}
	return (TRUE);
}

void	init_diner_setup(t_diner *diner_setup)
{
	diner_setup->philo_threads = NULL;
	diner_setup->philo_monitors = NULL;
	diner_setup->is_diner_over = FALSE;
}

static void	init_philo(t_philo *philo, int i,
						t_diner *diner_setup, t_config *config)
{
	t_mutexes	*mutexes;
	int			nb_philo;

	mutexes = &diner_setup->mutexes;
	nb_philo = config->nb_philo;
	philo->id = i + 1;
	philo->nb_meal = 0;
	philo->min_nb_meal = config->min_nb_meal;
	philo->time_to_die = config->time_to_die;
	philo->time_to_eat = config->time_to_eat;
	philo->time_to_sleep = config->time_to_sleep;
	philo->is_speaking = &mutexes->is_speaking;
	philo->forks = mutexes->forks;
	philo->is_eating = &mutexes->is_eating[i];
	philo->nb_forks = config->nb_philo;
	philo->fork_left = i;
	philo->fork_right = (i + 1) % nb_philo;
	philo->is_diner_over = &diner_setup->is_diner_over;
}

t_bool	init_philosophers(t_philo **philosophers, int nb_philo,
							t_diner *diner_setup, t_config *config)
{
	int			i;

	*philosophers = malloc(nb_philo * sizeof(t_philo));
	if (!*philosophers)
		return (print_error(PHILO_ALLOC, NULL, FALSE));
	i = 0;
	while (i < nb_philo)
	{
		init_philo(&(*philosophers)[i], i, diner_setup, config);
		i++;
	}
	return (TRUE);
}
