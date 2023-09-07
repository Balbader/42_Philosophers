/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:38:18 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/02 13:55:32 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo_utils.h"
#include "philo_parsing.h"
#include "philosophers.h"
#include "philo_init.h"
#include "philo_diner.h"

#define ERROR		-1

#define MTX_DESTROY	"A mutex couldn't be destroyed"

static void	clean_mutexes(t_mutexes *mutexes, int nb_philo)
{
	int		i;

	if (pthread_mutex_destroy(&mutexes->is_speaking) != 0)
		print_error(MTX_DESTROY, NULL, ERROR);
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_destroy(&mutexes->forks[i]) != 0)
			print_error(MTX_DESTROY, NULL, ERROR);
		if (pthread_mutex_destroy(&mutexes->is_eating[i++]) != 0)
			print_error(MTX_DESTROY, NULL, ERROR);
	}
	free(mutexes->forks);
	free(mutexes->is_eating);
}

static int	clean_exit(t_diner *diner_setup, t_philo *philosophers,
				int nb_philo, int return_value)
{
	int		i;

	if (diner_setup->philo_threads)
	{
		i = 0;
		while (i < nb_philo)
		{
			pthread_join(diner_setup->philo_threads[i], NULL);
			pthread_join(diner_setup->philo_monitors[i++], NULL);
		}
	}
	clean_mutexes(&diner_setup->mutexes, nb_philo);
	if (diner_setup->philo_threads)
		free(diner_setup->philo_threads);
	if (diner_setup->philo_monitors)
		free(diner_setup->philo_monitors);
	if (philosophers)
		free(philosophers);
	return (return_value);
}

int	main(int argc, char *argv[])
{
	t_config	config;
	int			nb_philo;
	t_diner		diner_setup;
	t_philo		*philosophers;

	if (!parse_config(argc, argv, &config))
		return (ERROR);
	nb_philo = config.nb_philo;
	if (!init_mutexes(&diner_setup.mutexes, nb_philo))
		return (ERROR);
	init_diner_setup(&diner_setup);
	if (!init_philosophers(&philosophers, nb_philo, &diner_setup, &config))
		return (clean_exit(&diner_setup, NULL, nb_philo, ERROR));
	if (!launch_diner(&diner_setup, philosophers, nb_philo))
		return (clean_exit(&diner_setup, philosophers, nb_philo, ERROR));
	if (config.min_nb_meal >= 0)
		monitor_nb_meals(philosophers, nb_philo, config.min_nb_meal);
	clean_exit(&diner_setup, philosophers, nb_philo, 0);
	return (0);
}
