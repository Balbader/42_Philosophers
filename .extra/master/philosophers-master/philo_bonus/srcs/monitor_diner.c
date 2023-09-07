/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_diner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:56:17 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/15 12:25:02 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include "boolean.h"
#include "philo_utils.h"
#include "philosophers.h"
#include "philo_diner.h"

static void	*monitor_diner_ending(void *arg)
{
	t_diner			*diner_setup;
	t_semaphores	*semaphores;

	diner_setup = (t_diner *)arg;
	semaphores = &diner_setup->semaphores;
	sem_wait(semaphores->diner_over);
	diner_setup->is_diner_over = TRUE;
	sem_post(semaphores->diner_over);
	return (arg);
}

static void	*monitor_nb_meal(void *arg)
{
	t_diner			*diner_setup;
	t_semaphores	*semaphores;
	int				nb_philo;
	int				i;

	diner_setup = (t_diner *)arg;
	semaphores = &diner_setup->semaphores;
	nb_philo = diner_setup->nb_philo;
	i = 0;
	while (i < nb_philo && !diner_setup->is_diner_over)
	{
		sem_wait(semaphores->reached_nb_meal);
		i++;
	}
	if (!diner_setup->is_diner_over)
		announce_nb_meal(diner_setup, semaphores);
	return (arg);
}

static void	join_threads(pthread_t *diner_ending_monitor,
							pthread_t *nb_meal_monitor, t_diner *diner_setup)
{
	int				nb_philo;
	t_semaphores	*semaphores;
	int				i;

	nb_philo = diner_setup->nb_philo;
	semaphores = &diner_setup->semaphores;
	sem_wait(semaphores->diner_over);
	diner_setup->is_diner_over = TRUE;
	sem_post(semaphores->diner_over);
	pthread_join(*diner_ending_monitor, NULL);
	if (nb_meal_monitor)
	{
		i = 0;
		while (i++ < nb_philo)
			sem_post(semaphores->reached_nb_meal);
		pthread_join(*nb_meal_monitor, NULL);
	}
}

t_bool	monitor_diner(t_diner *diner_setup, t_semaphores *semaphores)
{
	pthread_t	diner_ending_monitor;
	pthread_t	nb_meal_monitor;

	if (pthread_create(&diner_ending_monitor, NULL,
			&monitor_diner_ending, diner_setup) != 0)
	{
		sem_post(semaphores->diner_over);
		return (print_error(THREAD_CREATE, NULL, FALSE));
	}
	if (pthread_create(&nb_meal_monitor, NULL, &monitor_nb_meal, diner_setup))
	{
		sem_post(semaphores->diner_over);
		diner_setup->is_diner_over = TRUE;
		join_threads(&diner_ending_monitor, NULL, diner_setup);
		return (print_error(THREAD_CREATE, NULL, FALSE));
	}
	join_threads(&diner_ending_monitor, &nb_meal_monitor, diner_setup);
	return (TRUE);
}
