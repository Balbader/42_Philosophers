/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_diner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:56:17 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/15 12:41:12 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "boolean.h"
#include "philo_utils.h"
#include "philosophers.h"
#include "philo_diner.h"

#define CHILD_CREATE	"A child process couldn't be created"
#define ERROR			-1

static void	*monitor_diner_ending(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	sem_wait(philo->diner_over);
	philo->is_diner_over = TRUE;
	sem_post(philo->diner_over);
	return (arg);
}

static void	*monitor_philo(void *arg)
{
	t_philo		*philo;
	time_t		time;

	philo = (t_philo *)arg;
	while (!philo->is_diner_over)
	{
		sem_wait(philo->is_eating);
		time = get_time();
		if (!philo->is_diner_over
			&& (time - philo->last_meal) > philo->time_to_die)
		{
			if (philo->min_nb_meal >= 0 && philo->nb_meal == philo->min_nb_meal)
				ft_usleep(2000);
			if (!philo->is_diner_over)
				announce_death(philo, time);
		}
		sem_post(philo->is_eating);
		if (!philo->is_diner_over)
			ft_usleep(1000);
	}
	return (arg);
}

static void	clean_exit_child(t_diner *diner_setup,
						t_philo *philosophers, int nb_philo, int exit_value)
{
	t_semaphores	*semaphores;
	int				i;

	semaphores = &diner_setup->semaphores;
	diner_setup->philo_pids[0] = 0;
	free(diner_setup->philo_pids);
	sem_close(semaphores->forks);
	sem_close(semaphores->is_speaking);
	sem_close(semaphores->reached_nb_meal);
	sem_close(semaphores->diner_over);
	semaphores->diner_over = semaphores->is_eating[0];
	semaphores->is_eating[0] = semaphores->diner_over;
	i = 0;
	while (i < nb_philo)
		sem_close(semaphores->is_eating[i++]);
	free(semaphores->is_eating);
	semaphores->names[0][0] = '\0';
	i = 0;
	while (i < nb_philo)
		free(semaphores->names[i++]);
	free(semaphores->names);
	philosophers[0].is_diner_over = TRUE;
	free(philosophers);
	exit(exit_value);
}

static void	launch_child(t_diner *diner_setup,
							t_philo *philosophers, int i, int nb_philo)
{
	pthread_t	diner_ending_monitor;
	pthread_t	philo_monitor;

	if (pthread_create(&diner_ending_monitor, NULL,
			&monitor_diner_ending, &philosophers[i]) != 0)
	{
		sem_post(philosophers[i].diner_over);
		print_error(THREAD_CREATE, NULL, FALSE);
		return (clean_exit_child(diner_setup, philosophers, nb_philo, ERROR));
	}
	if (pthread_create(&philo_monitor, NULL,
			&monitor_philo, &philosophers[i]) != 0)
	{
		sem_post(philosophers[i].diner_over);
		pthread_join(diner_ending_monitor, NULL);
		print_error(THREAD_CREATE, NULL, FALSE);
		return (clean_exit_child(diner_setup, philosophers, nb_philo, ERROR));
	}
	if (diner_setup->min_nb_meal == 0)
		sem_post(diner_setup->semaphores.reached_nb_meal);
	diner(&philosophers[i]);
	pthread_join(diner_ending_monitor, NULL);
	pthread_join(philo_monitor, NULL);
	clean_exit_child(diner_setup, philosophers, nb_philo, 0);
}

t_bool	launch_diner(t_diner *diner_setup, t_philo *philosophers, int nb_philo)
{
	int			i;
	time_t		time;

	i = 0;
	time = get_time();
	while (i < nb_philo)
	{
		philosophers[i].last_meal = time;
		philosophers[i].start_time = time;
		diner_setup->philo_pids[i] = fork();
		if (diner_setup->philo_pids[i] == -1)
		{
			sem_post(diner_setup->semaphores.diner_over);
			return (print_error(CHILD_CREATE, NULL, FALSE));
		}
		if (diner_setup->philo_pids[i] == 0)
			launch_child(diner_setup, philosophers, i, nb_philo);
		i += 2;
		if (i % 2 == 0 && i >= nb_philo)
		{
			i = 1;
			ft_usleep(2000);
		}
	}
	return (TRUE);
}
